#include "Users_File.h"
#include "Markup.h"

void Users_File:: write_user_to_file (User user)
{
        CMarkup xml;
        bool file_exists = xml.Load (get_users_file_name());
        if (!file_exists)
        {
            xml.AddElem( "Users" );
        }

        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "User" );
        xml.IntoElem();
        xml.AddElem( "user_id", user.get_user_id() );
        xml.AddElem( "login", user.get_login() );
        xml.AddElem( "password", user.get_password() );
        xml.AddElem( "name", user.get_name() );
        xml.AddElem( "surname", user.get_surname() );
        xml.Save(get_users_file_name());
}

void Users_File::write_all_users_to_file(vector <User> & users)
{
    CMarkup xml;
    xml.AddElem( "Users" );
    xml.FindElem();
    xml.IntoElem();

    for (vector <User>::iterator it = users.begin(); it != users.end(); it++)
    {
        xml.AddElem( "User" );
        xml.IntoElem();
        xml.AddElem( "user_id", it -> get_user_id() );
        xml.AddElem( "login", it -> get_login() );
        xml.AddElem( "password", it -> get_password() );
        xml.AddElem( "name", it -> get_name() );
        xml.AddElem( "surname", it -> get_surname() );
        xml.OutOfElem();
    }

    xml.Save("temporary_file.xml");
    remove(get_users_file_name().c_str());
    rename("temporary_file.xml", get_users_file_name().c_str());
}


vector<User> Users_File::import_users_from_file ()
{
    vector<User> users;
    User user_from_file;
    CMarkup xml;

    bool file_exists = xml.Load (get_users_file_name().c_str());
    if (!file_exists)
    {
        cout << "file named: " << "(" << get_users_file_name() << ")" << " doesn't exist..." << endl; system("pause");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "user_id" );
        user_from_file.set_user_id(atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "login" );
        user_from_file.set_login(xml.GetData());
        xml.FindElem( "password" );
        user_from_file.set_password(xml.GetData());
        xml.FindElem( "name" );
        user_from_file.set_name(xml.GetData());
        xml.FindElem( "surname" );
        user_from_file.set_surname(xml.GetData());
        users.push_back(user_from_file);
        xml.OutOfElem();
    }

    return users;
}

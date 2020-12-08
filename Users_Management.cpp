#include "Users_Management.h"

void Users_Management::user_registration()
{
    User user = get_new_user_data();
    users.push_back(user);
    users_file.write_user_to_file(user);
    cout << endl << "New account created successfully" << endl << endl;
    system("pause");
}

User Users_Management::get_new_user_data()
{
    User user;
    user.set_user_id (get_new_user_id());
    string new_user_data ="";
    do
    {
        cout << "Type in login: ";
        cin >> new_user_data;
        user.set_login(new_user_data);

    } while (does_login_already_exist_check(user.get_login()) == true);

    cout << "Type in password: ";
    cin >> new_user_data;
    user.set_password(new_user_data);

    cout << "Type in your first name: ";
    cin >> new_user_data;
    user.set_name(Auxiliary_Methods::make_first_letter_capital(new_user_data));

    cout << "Type in your surname: ";
    cin >> new_user_data;
    user.set_surname(Auxiliary_Methods::make_first_letter_capital (new_user_data));

    return user;
}

int Users_Management::get_new_user_id()
{
   return (users.empty()) ? 1 : users.back().get_user_id() + 1;
}

bool Users_Management::does_login_already_exist_check(string login)
{
    for (int i=0; i < users.size(); i++)
    {
        if (users[i].get_login() == login)
        {
            cout << endl << "User of that login already exists - use different login... " << endl;
            return true;
        }
    }
    return false;
}
void Users_Management::user_login()
{
    string login ="", password ="";
    cout << endl << "Please type in the login: ";
    cin >> login;

    vector <User> ::iterator it = users.begin();
    while (it != users.end())
    {
        if (it -> get_login() == login)
        {
            for (int number_of_attempts = 3; number_of_attempts > 0; number_of_attempts --)
            {
                cout<<"Type in your password. Attempts left ("<< number_of_attempts <<"): ";
                cin>> password;
                if (it -> get_password() == password)
                {
                    cout << "You are logged in," << endl;
                    logged_user_id = it -> get_user_id();
                    system ("pause");
                    return;
                }
            }
            cout<<"You have tried 3 times with incorrect password. Wait 5 seconds."<<endl;
            Sleep(5000);
            return;
        }
      it++;
    }
    cout << "This login was not registered before ..." << endl << system("pause");

}

void Users_Management:: password_change()
{
    string new_password = "";
    cout << "Type in new password: ";
    cin >> new_password;

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].get_user_id() == logged_user_id)
        {
            users[i].set_password(new_password);
            cout << "Password has been updated..." << endl << endl;
            system("pause");
        }
    }
    users_file.write_all_users_to_file(users);
}

void Users_Management::user_logout()
{
    if (logged_user_id != 0) logged_user_id = 0;
    else {cout << "Nobody is logged in at present." << endl; system ("pause");}

}

bool Users_Management::is_user_logged_in_check()
{
    if (logged_user_id != 0) return true;
    else return false;
}

int Users_Management::get_logged_user_id()
{
    return logged_user_id;
}

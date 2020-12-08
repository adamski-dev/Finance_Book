#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int user_id;
    string login, password, name, surname;

   public:
        User (int user_id=0, string login="", string password="", string name="", string surname="")
       {
           this ->user_id = user_id;
           this ->login = login;
           this ->password = password;
           this ->name = name;
           this ->surname = surname;
       }
       void set_user_id (int new_user_id);
       void set_login (string new_login);
       void set_password (string new_password);
       void set_name (string new_name);
       void set_surname (string new_surname);

       int get_user_id();
       string get_login();
       string get_password();
       string get_name();
       string get_surname();
};

#endif

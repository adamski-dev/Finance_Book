#include "User.h"

void User::set_user_id (int new_user_id)
{
    if (new_user_id >= 0)
    user_id = new_user_id;
}
void User::set_login (string new_login)
{
    login = new_login;
}
void User::set_password (string new_password)
{
    password = new_password;
}
void User::set_name (string new_name)
{
    name = new_name;
}
void User::set_surname (string new_surname)
{
    surname = new_surname;
}


int User::get_user_id()
{
    return user_id;
}
string User::get_login()
{
    return login;
}
string User::get_password()
{
    return password;
}
string User::get_name()
{
    return name;
}
string User::get_surname()
{
    return surname;
}
#ifndef USERS_MANAGEMENT_H
#define USERS_MANAGEMENT_H
#include <vector>
#include "User.h"
#include "Users_File.h"
#include "Auxiliary_Methods.h"


using namespace std;

class Users_Management
{
    int logged_user_id;
    vector<User> users;
    User get_new_user_data();
    int get_new_user_id();
    bool does_login_already_exist_check (string login);
    Users_File users_file;

public:
    Users_Management(){logged_user_id =0; users = users_file.import_users_from_file();};
    void user_login();
    void user_registration();
    void password_change();
    void user_logout();
    bool is_user_logged_in_check();
    int get_logged_user_id();
};

#endif

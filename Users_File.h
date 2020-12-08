#ifndef USERS_FILE_H
#define USERS_FILE_H
#include <iostream>
#include <vector>
#include "User.h"
#include "Xml_File.h"

using namespace std;


class Users_File: public Xml_File
{

public:

    void write_user_to_file (User user);
    vector<User> import_users_from_file ();
    void write_all_users_to_file (vector <User> & users);
};

#endif

#ifndef XML_FILE_H
#define XML_FILE_H
#include <iostream>

using namespace std;

class Xml_File
{
    const string USERS_FILE_NAME = "users.xml";
    const string INCOMES_FILE_NAME = "incomes.xml";
    const string EXPENSES_FILE_NAME = "expenses.xml";

public:

    string get_users_file_name();
    string get_incomes_file_name();
    string get_expenses_file_name();
};

#endif

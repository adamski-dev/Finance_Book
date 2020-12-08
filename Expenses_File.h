#ifndef EXPENSES_FILE_H
#define EXPENSES_FILE_H
#include <iostream>
#include <vector>
#include "Expense.h"
#include "Xml_File.h"

using namespace std;


class Expenses_File: public Xml_File
{
    int last_expense_id_number;

public:

    void write_expense_to_file (Expense expense);
    vector<Expense> import_expenses_from_file (int logged_user_id);
    int get_last_expense_id ();

};

#endif

#ifndef FINANCE_MANAGEMENT_H
#define FINANCE_MANAGEMENT_H
#include <vector>
#include <windows.h>
#include <algorithm>
#include "Income.h"
#include "Incomes_File.h"
#include "Expense.h"
#include "Expenses_File.h"
#include "Auxiliary_Methods.h"

using namespace std;

class Finance_Management
{
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    Incomes_File incomes_file;
    Expenses_File expenses_file;

public:
    Finance_Management (int logged_user_id): LOGGED_USER_ID(logged_user_id){incomes = incomes_file.import_incomes_from_file(LOGGED_USER_ID); expenses = expenses_file.import_expenses_from_file(LOGGED_USER_ID);};
    void add_income();
    void add_expense();
    void current_month_data_sheet_display ();
    void last_month_data_sheet_display ();
    void set_date_period_data_sheet_display ();

};

#endif

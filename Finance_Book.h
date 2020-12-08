#ifndef FINANCE_BOOK_H
#define FINANCE_BOOK_H
#include "Users_Management.h"
#include "Finance_Management.h"

using namespace std;

class Finance_Book
{
    Users_Management users_management;
    Finance_Management *finance_management;

public:
    Finance_Book (){finance_management = NULL;};
    ~Finance_Book (){delete finance_management; finance_management = NULL;};
    void user_registration();
    void user_login();
    void password_change();
    void user_logout();
    void main_menu_display();
    bool is_user_logged_in_check();
    void finance_menu_display();
    void add_income();
    void add_expense();
    void current_month_data_sheet_display();
    void last_month_data_sheet_display();
    void set_date_period_data_sheet_display ();
};

#endif

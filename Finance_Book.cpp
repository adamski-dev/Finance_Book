#include "Finance_Book.h"

void Finance_Book::user_registration()
{
    users_management.user_registration();
}

void Finance_Book::user_login()
{
    users_management.user_login();
    if (users_management.is_user_logged_in_check())
    {
        finance_management = new Finance_Management (users_management.get_logged_user_id());
    }
}

void Finance_Book::password_change()
{
    users_management.password_change();
}

void Finance_Book::user_logout ()
{
    users_management.user_logout();
    delete finance_management; finance_management = NULL;
}

bool Finance_Book:: is_user_logged_in_check()
{
    if (users_management.is_user_logged_in_check()) return true;
    else return false;
}

void Finance_Book:: add_income()
{
    if (users_management.is_user_logged_in_check())
    finance_management -> add_income();
}

void Finance_Book:: add_expense()
{
    if (users_management.is_user_logged_in_check())
    finance_management -> add_expense();
}

void Finance_Book:: current_month_data_sheet_display()
{
    finance_management -> current_month_data_sheet_display();
}
void Finance_Book:: last_month_data_sheet_display()
{
  finance_management -> last_month_data_sheet_display();
}

void Finance_Book:: set_date_period_data_sheet_display ()
{
  finance_management -> set_date_period_data_sheet_display();
}

void Finance_Book::main_menu_display()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "---------------------------"                       << endl;
    cout << " Main menu:"                                       << endl;
    cout << "---------------------------"                       << endl;
    cout << "1. Login "                                         << endl;
    cout << "2. Registration"                                   << endl;
    cout << "3. End program"                                    << endl;
    cout << "---------------------------"                       << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void Finance_Book::finance_menu_display()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout << "---------------------------"                         << endl;
    cout << " Finance menu:"                                      << endl;
    cout << "---------------------------"                         << endl;
    cout << "1. Add income "                                      << endl;
    cout << "2. Add expense"                                      << endl;
    cout << "3. Current month data sheet and balance"             << endl;
    cout << "4. Last month data sheet and balance"                << endl;
    cout << "5. Set date period data sheet and balance"           << endl;
    cout << "6. Password change"                                  << endl;
    cout << "7. Sign out"                                         << endl;
    cout << "---------------------------"                         << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

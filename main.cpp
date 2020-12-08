#include <iostream>
#include "Finance_Book.h"

using namespace std;

int main()
{
    Finance_Book finance_book;
    while (true)
    {
        finance_book.main_menu_display();
        char select;
        cout << endl << "Select:";
        cin >> select;

        switch (select)
        {
        case '1': finance_book.user_login(); break;
        case '2': finance_book.user_registration(); break;
        case '3': exit(0); break;
        }

        while (finance_book.is_user_logged_in_check())
        {
            finance_book.finance_menu_display();
            cout << endl << "Select:";
            cin >> select;
            switch (select)
            {
            case '1': finance_book.add_income(); break;
            case '2': finance_book.add_expense(); break;
            case '3': finance_book.current_month_data_sheet_display(); break;
            case '4': finance_book.last_month_data_sheet_display(); break;
            case '5': finance_book.set_date_period_data_sheet_display(); break;
            case '6': finance_book.password_change(); break;
            case '7': finance_book.user_logout(); break;
            }
        }
    }

    return 0;
}

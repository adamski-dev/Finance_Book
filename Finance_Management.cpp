#include "Finance_Management.h"

void Finance_Management::add_income()
{
    Income income;
    income.set_id_number(incomes_file.get_last_income_id()+1);
    income.set_user_id(LOGGED_USER_ID);

    char select;
    string user_specified_date ="";
    cout << "Please type in letter Y if you would like to log income with today's date, " << endl;
    cout << "or letter N if different: ";
    cin >> select;

    while ((select != 'Y')&&(select != 'y')&&(select != 'N')&&(select != 'n'))
    {
            cout << "Please type in letter Y if you would like to log income with today's date, " << endl;
            cout << "or letter N if different: ";
            cin >> select;
    }
    if ((select == 'Y')||(select == 'y')) income.set_date(Auxiliary_Methods::get_todays_date());
    if ((select == 'N')||(select == 'n'))
    {
        cout << endl << "Enter date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
        cin >> user_specified_date;
        while (!(Auxiliary_Methods::user_specified_date_validation(user_specified_date)))
        {
            cout << endl << "Enter date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
            cin >> user_specified_date;
        }
        if (Auxiliary_Methods::user_specified_date_validation(user_specified_date)) income.set_date(user_specified_date);
    }

    string amount = "";
    cout << endl << "Type in source of income: ";
    cin.sync();
    getline (cin, amount);
    income.set_item(amount);

    cout << endl << "Type in amount of income, " << endl;
    cout << "If amount is a decimal number (sample: 1450.25)," << endl;
    cout << "please use a dot between numbers like in the sample: ";
    cin >> amount;

    while (!Auxiliary_Methods::amount_entered_by_user_validation(amount))
    {
       cout << endl << "Type in amount in correct format: ";
       cin >> amount;
    }

    if (Auxiliary_Methods::amount_entered_by_user_validation(amount)) income.set_amount(amount);

    incomes.push_back(income);
    incomes_file.write_income_to_file(income);
}

void Finance_Management::add_expense()
{
    Expense expense;
    expense.set_id_number(expenses_file.get_last_expense_id()+1);
    expense.set_user_id(LOGGED_USER_ID);

    char select;
    string user_specified_date ="";
    cout << "Please type in letter Y if you would like to log expense with today's date, " << endl;
    cout << "or letter N if different: ";
    cin >> select;

    while ((select != 'Y')&&(select != 'y')&&(select != 'N')&&(select != 'n'))
    {
            cout << "Please type in letter Y if you would like to log expense with today's date, " << endl;
            cout << "or letter N if different: ";
            cin >> select;
    }

    if ((select == 'Y')||(select == 'y')) expense.set_date(Auxiliary_Methods::get_todays_date());
    if ((select == 'N')||(select == 'n'))
    {
        cout << endl << "Enter date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
        cin >> user_specified_date;
        while (!(Auxiliary_Methods::user_specified_date_validation(user_specified_date)))
        {
            cout << endl << "Enter date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
            cin >> user_specified_date;
        }
        if (Auxiliary_Methods::user_specified_date_validation(user_specified_date)) expense.set_date(user_specified_date);
    }

    string amount = "";
    cout << endl << "Type in source of expense: ";
    cin.sync();
    getline (cin, amount);
    expense.set_item(amount);cout << endl << "Type in amount of expense, " << endl;
    cout << "If amount is a decimal number (sample: 1450.25)," << endl;
    cout << "please use a dot between numbers like in the sample: ";
    cin >> amount;

    while (!Auxiliary_Methods::amount_entered_by_user_validation(amount))
    {
       cout << endl << "Type in amount in correct format: ";
       cin >> amount;
    }

    if (Auxiliary_Methods::amount_entered_by_user_validation(amount)) expense.set_amount(amount);

    expenses.push_back(expense);
    expenses_file.write_expense_to_file(expense);
}

void Finance_Management::current_month_data_sheet_display()
{
    sort( incomes.begin( ), incomes.end( ), [ ]( Income & low_date, Income & high_date ){return low_date.get_date() < high_date.get_date();});
    sort( expenses.begin( ), expenses.end( ), [ ]( Expense & low_date, Expense & high_date ){return low_date.get_date() < high_date.get_date();});


    float sum_of_incomes = 0;
    float sum_of_expenses = 0;

    cout << endl << "-----------------------------------------------------------------" << endl;

    cout << "Incomes: " << endl << endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if (incomes[i].get_date() >= Auxiliary_Methods::get_first_day_of_current_month())
        {
            sum_of_incomes += stof(incomes[i].get_amount());
            cout << "Date: " << incomes[i].get_date() << "     ";
            cout << "Amount: " << incomes[i].get_amount() << Auxiliary_Methods::set_gap_size(incomes[i].get_amount());
            cout << "Item: " << incomes[i].get_item() << endl;
        }

    }
    cout << endl <<  "The sum of all incomes this month =  " << sum_of_incomes << endl;
    cout << endl << endl << "Expenses: " << endl << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if (expenses[i].get_date() >= Auxiliary_Methods::get_first_day_of_current_month())
        {
            sum_of_expenses += stof(expenses [i].get_amount());
            cout <<  "Date: " << expenses[i].get_date() << "     ";
            cout << "Amount: " << expenses[i].get_amount() << Auxiliary_Methods::set_gap_size(expenses[i].get_amount());
            cout << "Item: " << expenses[i].get_item() << endl;
        }
    }
    cout << endl <<  "The sum of all expenses this month =  " << sum_of_expenses << endl;
    cout << endl << "-----------------------------------------------------------------" << endl;
    if (sum_of_incomes > sum_of_expenses) cout << "You have generated: " << sum_of_incomes - sum_of_expenses << " euro savings this month.";
    if (sum_of_incomes < sum_of_expenses) cout << "Your expenses this month exceeded your incomes by: " << sum_of_expenses - sum_of_incomes << " euro.";
    if (sum_of_incomes == sum_of_expenses) cout << "Your expenses are equal to your incomes this month.";
    cout << endl << endl << system ("pause");
}

void Finance_Management::last_month_data_sheet_display()
{
    sort( incomes.begin( ), incomes.end( ), [ ]( Income & low_date, Income & high_date ){return low_date.get_date() < high_date.get_date();});
    sort( expenses.begin( ), expenses.end( ), [ ]( Expense & low_date, Expense & high_date ){return low_date.get_date() < high_date.get_date();});

    float sum_of_incomes = 0;
    float sum_of_expenses = 0;

    cout << endl << "-----------------------------------------------------------------" << endl;

    cout << "Incomes: " << endl << endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if ((incomes[i].get_date() >= Auxiliary_Methods::get_first_day_of_last_month()) && (incomes[i].get_date() < Auxiliary_Methods::get_first_day_of_current_month()))
        {
            sum_of_incomes += stof(incomes[i].get_amount());
            cout << "Date: " << incomes[i].get_date() <<  "     ";
            cout << "Amount: " << incomes[i].get_amount() << Auxiliary_Methods::set_gap_size(incomes[i].get_amount());
            cout << "Item: " << incomes[i].get_item() << endl;
        }

    }
    cout << endl <<  "The sum of all incomes last month =  " << sum_of_incomes << endl;
    cout << endl << endl << "Expenses: " << endl << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if ((expenses[i].get_date() >= Auxiliary_Methods::get_first_day_of_last_month()) && (expenses[i].get_date() < Auxiliary_Methods::get_first_day_of_current_month()))
        {
            sum_of_expenses += stof(expenses [i].get_amount());
            cout <<  "Date: " << expenses[i].get_date() <<  "     ";
            cout << "Amount: " << expenses[i].get_amount() << Auxiliary_Methods::set_gap_size(expenses[i].get_amount());
            cout << "Item: " << expenses[i].get_item() << endl;
        }
    }
    cout << endl <<  "The sum of all expenses last month =  " << sum_of_expenses << endl;
    cout << endl << "-----------------------------------------------------------------" << endl;
    if (sum_of_incomes > sum_of_expenses) cout << "You have generated: " << sum_of_incomes - sum_of_expenses << " euro savings last month.";
    if (sum_of_incomes < sum_of_expenses) cout << "Your expenses last month exceeded your incomes by: " << sum_of_expenses - sum_of_incomes << " euro.";
    if (sum_of_incomes == sum_of_expenses) cout << "Your expenses are equal to your incomes last month.";
    cout << endl << endl << system ("pause");
}

void Finance_Management::set_date_period_data_sheet_display ()
{
    sort( incomes.begin( ), incomes.end( ), [ ]( Income& low_date, Income& high_date ){return low_date.get_date() < high_date.get_date();});
    sort( expenses.begin( ), expenses.end( ), [ ]( Expense & low_date, Expense & high_date ){return low_date.get_date() < high_date.get_date();});

    float sum_of_incomes = 0;
    float sum_of_expenses = 0;

    string user_specified_date_from ="";
    string user_specified_date_to ="";

    cout << endl << "Type in start date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
    cin >> user_specified_date_from;

    while (!(Auxiliary_Methods::user_specified_date_validation(user_specified_date_from)))
    {
        cout << endl << "Type in start date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000: ";
        cin >> user_specified_date_from;
    }

    cout << endl << "Type in end date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000:  ";
    cin >> user_specified_date_to;

    while (!(Auxiliary_Methods::user_specified_date_validation(user_specified_date_to)))
    {
        cout << endl << "Type in end date in format: YYYY-MM-DD (year-month-day). The year can't be less than 2000: ";
        cin >> user_specified_date_to;
    }

    cout << endl << "-----------------------------------------------------------------" << endl;

    cout << "Incomes: " << endl << endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if ((incomes[i].get_date() >= user_specified_date_from) && (incomes[i].get_date() <= user_specified_date_to))
        {
            sum_of_incomes += stof(incomes[i].get_amount());
            cout << "Date: " << incomes[i].get_date() <<  "     ";
            cout << "Amount: " << incomes[i].get_amount() << Auxiliary_Methods::set_gap_size(incomes[i].get_amount());
            cout << "Item: " << incomes[i].get_item() << endl;
        }

    }
    cout << endl <<  "The sum of incomes during that time =  " << sum_of_incomes << endl;
    cout << endl << endl << "Expenses: " << endl << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if ((expenses[i].get_date() >= user_specified_date_from) && (expenses[i].get_date() <= user_specified_date_to))
        {
            sum_of_expenses += stof(expenses [i].get_amount());
            cout <<  "Date: " << expenses[i].get_date() <<  "     ";
            cout << "Amount: " << expenses[i].get_amount() << Auxiliary_Methods::set_gap_size(expenses[i].get_amount());
            cout << "Item: " << expenses[i].get_item() << endl;
        }
    }
    cout << endl <<  "The sum of expenses during that time = "  << sum_of_expenses << endl;
    cout << endl << "-----------------------------------------------------------------" << endl;
    if (sum_of_incomes > sum_of_expenses) cout << "You have generated: " << sum_of_incomes - sum_of_expenses << " euro savings in the set date period.";
    if (sum_of_incomes < sum_of_expenses) cout << "Your expenses in the set date period exceeded your incomes by: " << sum_of_expenses - sum_of_incomes << " euro.";
    if (sum_of_incomes == sum_of_expenses) cout << "Your expenses are equal to your incomes in the set date period.";
    cout << endl << endl << system ("pause");
}


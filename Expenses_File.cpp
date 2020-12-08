#include "Expenses_File.h"
#include "Markup.h"

void Expenses_File:: write_expense_to_file (Expense expense)
{
        CMarkup xml;
        bool file_exists = xml.Load (get_expenses_file_name());
        if (!file_exists)
        {
            last_expense_id_number = 0;
            xml.AddElem( "Expenses" );
        }

        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "Expense" );
        xml.IntoElem();
        xml.AddElem( "expense_id", expense.get_id_number() );
        xml.AddElem( "user_id", expense.get_user_id() );
        xml.AddElem( "date", expense.get_date() );
        xml.AddElem( "item", expense.get_item() );
        xml.AddElem( "amount", expense.get_amount() );
        xml.Save(get_expenses_file_name() );

        last_expense_id_number++;
}

vector<Expense> Expenses_File::import_expenses_from_file (int logged_user_id)
{
    vector<Expense> expenses;
    Expense expense_from_file;
    CMarkup xml;

    bool file_exists = xml.Load (get_expenses_file_name().c_str());

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "expense_id" );
        expense_from_file.set_id_number(atoi( MCD_2PCSZ(xml.GetData()) ));
        last_expense_id_number = expense_from_file.get_id_number();
        xml.FindElem( "user_id" );
        expense_from_file.set_user_id (atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "date" );
        expense_from_file.set_date(xml.GetData());
        xml.FindElem( "item" );
        expense_from_file.set_item(xml.GetData());
        xml.FindElem( "amount" );
        expense_from_file.set_amount(xml.GetData());
        if (expense_from_file.get_user_id() == logged_user_id) expenses.push_back(expense_from_file);
        xml.OutOfElem();
    }

    return expenses;
}

int Expenses_File:: get_last_expense_id()
{
  return last_expense_id_number;
}

#include "Incomes_File.h"
#include "Markup.h"

void Incomes_File:: write_income_to_file (Income income)
{
        CMarkup xml;
        bool file_exists = xml.Load (get_incomes_file_name());
        if (!file_exists)
        {
            last_income_id_number = 0;
            xml.AddElem( "Incomes" );
        }

        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "Income" );
        xml.IntoElem();
        xml.AddElem( "income_id", income.get_id_number() );
        xml.AddElem( "user_id", income.get_user_id() );
        xml.AddElem( "date", income.get_date() );
        xml.AddElem( "item", income.get_item() );
        xml.AddElem( "amount", income.get_amount() );
        xml.Save(get_incomes_file_name() );

        last_income_id_number++;
}

vector<Income> Incomes_File::import_incomes_from_file (int logged_user_id)
{
    vector<Income> incomes;
    Income income_from_file;
    CMarkup xml;

    bool file_exists = xml.Load (get_incomes_file_name().c_str());

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "income_id" );
        income_from_file.set_id_number(atoi( MCD_2PCSZ(xml.GetData()) ));
        last_income_id_number = income_from_file.get_id_number();
        xml.FindElem( "user_id" );
        income_from_file.set_user_id (atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "date" );
        income_from_file.set_date(xml.GetData());
        xml.FindElem( "item" );
        income_from_file.set_item(xml.GetData());
        xml.FindElem( "amount" );
        income_from_file.set_amount(xml.GetData());
        if (income_from_file.get_user_id() == logged_user_id) incomes.push_back(income_from_file);
        xml.OutOfElem();
    }

    return incomes;
}

int Incomes_File:: get_last_income_id()
{
  return last_income_id_number;
}

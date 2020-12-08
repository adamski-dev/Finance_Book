#include "Auxiliary_Methods.h"

string Auxiliary_Methods:: int_to_string_convert (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int Auxiliary_Methods::string_to_int_convert (string text)
{
    std::string str = text;
    int k;
    std::istringstream iss(str);
    iss >> k;
    return k;
}

int Auxiliary_Methods:: check_how_many_days_has_this_month(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
    {
        if (((year%4 == 0) && (year%100 !=0)) || (year%400 == 0)) return 29;
        else return 28;
    }
    break;
    }
}

bool Auxiliary_Methods:: user_specified_date_format_check (string date)
{
    if ((date[4] != '-')||(date[7] != '-')||(date.size()!=10))
    {
        cout << "Date entered in incorrect format...";
        Sleep (2000);
        return false;
    }

    for (int i=0; i<10; i++)
    {
        if ((i == 4) || (i == 7)) i++;
        if ((date[i] == '0')||(date[i] == '1')||(date[i] == '2')||(date[i] == '3')||(date[i] == '4')||(date[i] == '5')||(date[i] == '6')||(date[i] == '7')||(date[i] == '8')||(date[i] == '9'))
        {
            continue;
        }
        else
        {
            cout << "Date entered in incorrect format...";
            Sleep (2000);
            return false;
        }
    }
    return true;
}

bool Auxiliary_Methods:: user_specified_date_check (string date)
{
   SYSTEMTIME st;
   GetSystemTime(&st);
   string year_data = "", month_data = "", day_data = "";
   int year = 0, month = 0, day = 0;

   for (int i=0; i<4; i++) { year_data += date[i];}
   for (int i=0; i<2; i++) { month_data += date[i+5]; day_data += date[i+8];}

   year = string_to_int_convert(year_data);
   month = string_to_int_convert(month_data);
   day = string_to_int_convert(day_data);

   if ((year < 2000) || (year > st.wYear)) {cout << "Year must be between 2000 and now... "; Sleep (2000); return false;}
   if ((month < 1) || (month > 12)) {cout << "Month must be between 1 and 12... "; Sleep (2000); return false;}
   if ((day < 1) || (day > check_how_many_days_has_this_month(year, month)))
   {
       cout << "Day must be between 1 and " << check_how_many_days_has_this_month(year, month) << "..";
       Sleep (2000);
       return false;
   }
   if ( date > get_todays_date())
   {
       cout << "Date cannot be greater than today's date..";
       Sleep (2000);
       return false;
   }

   return true;
}

string Auxiliary_Methods::get_todays_date()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    string month = int_to_string_convert(st.wMonth);
    string day = int_to_string_convert(st.wDay);
    if (st.wMonth < 10) month = "0" + int_to_string_convert (st.wMonth);
    if (st.wDay <10) day = "0" + int_to_string_convert (st.wDay);
    string todays_date = "";
    todays_date = int_to_string_convert(st.wYear) +"-"+ month +"-"+ day;
    return todays_date;
}
string Auxiliary_Methods::get_first_day_of_current_month ()
{
    string first_day_of_this_month = get_todays_date();
    first_day_of_this_month[8] = '0' ; first_day_of_this_month[9] = '1';
    return first_day_of_this_month;
}

string Auxiliary_Methods:: get_first_day_of_last_month()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    string last_month = int_to_string_convert(st.wMonth-1);
    string day = "01";
    if ((st.wMonth -1 < 10) && (st.wMonth -1 !=0)) last_month = "0" + int_to_string_convert(st.wMonth-1);
    if (st.wMonth -1 == 0) last_month = "12";
    string first_day_of_last_month = int_to_string_convert(st.wYear) +"-"+ last_month +"-"+ day;
    return first_day_of_last_month;
}

bool Auxiliary_Methods:: amount_entered_by_user_validation (string & text)
{
    int number_of_commas = 0;
    int number_of_dots = 0;

    for (int i=0; i<text.size(); i++)
    {
        if (text[i] == ',')
        {
            text[i] = '.';
            number_of_commas++;
        }
        if (text[i] == '.') number_of_dots++;

        if ((text[i] != '.') && ((text[i] != '0')&&(text[i] != '1')&&(text[i] != '2')&&(text[i] != '3')&&(text[i] != '4')&&(text[i] != '5')&&(text[i] != '6')&&(text[i] != '7')&&(text[i] != '8')&&(text[i] != '9')))
        {
            cout << "Data entered in incorrect format.. "; Sleep (2000);
            return false;
        }
        if ((text[i] == '.') || (text[i] == '0')||(text[i] == '1')||(text[i] == '2')||(text[i] == '3')||(text[i] == '4')||(text[i] == '5')||(text[i] == '6')||(text[i] == '7')||(text[i] == '8')||(text[i] == '9'))
        {
            continue;
        }
    }

    if ((number_of_commas > 1)||(number_of_dots > 1)) {cout << "Data entered in incorrect format.. "; Sleep (2000); return false;}
    if ((text[0] == ',') || (text[0] == '.')) {cout << "Data entered in incorrect format.. "; Sleep (2000); return false;}

    return true;
}
bool Auxiliary_Methods:: user_specified_date_validation (string date)
{
    if ((user_specified_date_format_check(date))&&(user_specified_date_check(date))) return true;
    else return false;
}


string Auxiliary_Methods::set_gap_size (string amount)
{
    string gap_size = "               ";
    gap_size.erase (1,amount.size());
    return gap_size;
}

string Auxiliary_Methods::make_first_letter_capital(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

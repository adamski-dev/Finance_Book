#ifndef AUXILIARY_METHODS_H
#define AUXILIARY_METHODS_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

class Auxiliary_Methods
{


public:

    static bool user_specified_date_validation (string date);
    static string get_todays_date();
    static bool user_specified_date_format_check (string date);
    static bool user_specified_date_check (string date);
    static bool amount_entered_by_user_validation (string & text);
    static string int_to_string_convert (int number);
    static int string_to_int_convert (string text);
    static int check_how_many_days_has_this_month(int year, int month);
    static string get_first_day_of_current_month ();
    static string get_first_day_of_last_month();
    static string set_gap_size (string amount);
    static string make_first_letter_capital(string text);

};

#endif










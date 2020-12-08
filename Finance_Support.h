#ifndef FINANCE_SUPPORT_H
#define FINANCE_SUPPORT_H

#include <iostream>

using namespace std;

class Finance_Support
{
    int id_number, user_id;
    string date, item, amount;

   public:
       Finance_Support (int id_number=0, int user_id=0, string date="", string item="", string amount="")
       {
           this ->id_number = id_number;
           this ->user_id = user_id;
           this ->date = date;
           this ->item = item;
           this ->amount = amount;
       }
       void set_id_number (int new_id_number);
       void set_user_id (int new_user_id);
       void set_date (string new_date);
       void set_item (string new_item);
       void set_amount (string new_amount);

       int get_id_number();
       int get_user_id();
       string get_date();
       string get_item();
       string get_amount();
};

#endif

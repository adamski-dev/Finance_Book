#include "Finance_Support.h"

void Finance_Support::set_id_number (int new_id_number)
{
    if (new_id_number >= 0)
    id_number = new_id_number;
}

void Finance_Support::set_user_id (int new_user_id)
{
    if (new_user_id != 0)
    user_id = new_user_id;
}

void Finance_Support::set_date (string new_date)
{
    date = new_date;
}

void Finance_Support::set_item (string new_item)
{
    item = new_item;
}

void Finance_Support::set_amount (string new_amount)
{
    amount = new_amount;
}

int Finance_Support::get_id_number()
{
    return id_number;
}

int Finance_Support::get_user_id()
{
    return user_id;
}

string Finance_Support::get_date()
{
    return date;
}
string Finance_Support::get_item()
{
    return item;
}
string Finance_Support::get_amount()
{
    return amount;
}


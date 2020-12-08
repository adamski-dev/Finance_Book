#ifndef INCOMES_FILE_H
#define INCOMES_FILE_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "Xml_File.h"

using namespace std;


class Incomes_File: public Xml_File
{
    int last_income_id_number;

public:

    Incomes_File(){last_income_id_number = 0;};
    void write_income_to_file (Income income);
    vector<Income> import_incomes_from_file (int logged_user_id);
    int get_last_income_id ();

};

#endif

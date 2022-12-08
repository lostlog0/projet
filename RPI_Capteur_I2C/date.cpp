#include "date.hpp"
using namespace std;

    // Constructeur
Date::Date(){};

   // Assenseurs
string Date::getDate()
{
    return m_date;
}

void Date::setDate(string date)
{
    m_date = date;
}
    // Méthodes
void Date::demande_date()
{
    time_t tmm = time(0);
    m_date = ctime(&tmm);
}
 

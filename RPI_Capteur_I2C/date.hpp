#ifndef date_hpp
#define date_hpp
#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>

class Date 
{
    
protected:
    // Attribut
    std::string m_date;
    
public:
    // Assenseurs
    std::string getDate();
    void setDate(std::string date);

    // Méthodes
    Date();
    void demande_date();
};
#endif

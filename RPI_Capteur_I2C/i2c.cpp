#include "i2c.hpp"

using namespace std;

    // Assenseurs
float capteur::getTemp()
{
    return m_Temp;
}

void capteur::setTemp(float Temp)
{
    m_Temp = Temp;
}

string capteur::gettemperature()
{
    return m_temperature;
}

void capteur::settemperature(string temperature)
{
    m_temperature = temperature;
}
 
    // Méthodes
void capteur::relever_Temp()
{
    int m_file;
    const char* m_bus = "/dev/i2c-1";
    m_file = open (m_bus, O_RDWR);
    if(m_file < 0)
    {
        cout<<"Bus I2C inexistant. \n";
        exit(1);
    }
    
    ioctl(m_file, I2C_SLAVE, 0x40);
    char data[2] = {0};
    char config[1] = {0xE3};
    write (m_file,config, 1);
    sleep(1);
    if(read(m_file,data,2) != 2)
    {
        cout<<"Erreur : Longueur incorrecte \n";
    }
    else
    {
        m_Temp = (((data[0]* 256 + data[1])* 175.72) / 65536.0)-46.85;
    }
}

void capteur::convertion()
{
    m_temperature = std::to_string(m_Temp);
}



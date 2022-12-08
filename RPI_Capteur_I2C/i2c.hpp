#ifndef i2c_hpp
#define i2c_hpp

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include <unistd.h>


using namespace std;
class capteur 
{
        // Attributs
    protected:
        std::string m_temperature;
        float m_Temp;

    public:
        // Assenceurs
        void setTemp(float Temp);
        float getTemp();
        void settemperature(std::string temperature);
        std::string gettemperature();
        
        // Méthodes
        void relever_Temp();
        void convertion();
};  
#endif

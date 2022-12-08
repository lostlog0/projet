#include "date.hpp"
#include "stockage.hpp"
#include "i2c.hpp"
#include "socket.hpp"
#include <unistd.h>
#include <string>

#define EVER ;;

using namespace std;
int main()
{
        string valeur;
        string jour;
    for(EVER)
    {
        //Objet Capteur i2c
        capteur i2c;
        i2c.relever_Temp();
        i2c.convertion();
        valeur = i2c.gettemperature();
    
        // Objet Date
        Date date_class;
        date_class.demande_date();
        jour = date_class.getDate();

        // Objet Stockage
        Stockage stock(jour,valeur);
        stock.imbrication_date_valeur();
        stock.ecriture_log();
        string regroupement = stock.getEcriture();

        // Objet Socket
        mainsocket transmition(50125);
        transmition.setmessage(regroupement);
        transmition.envoie("172.20.200.121");
        
        sleep(15);
    }
}

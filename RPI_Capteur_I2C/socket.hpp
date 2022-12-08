#ifndef socket_hpp
#define socket_hpp

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>

class mainsocket
{
        // Attributs
    protected:
        int m_port_ecoute;
        std::string m_valeur;
        std::string m_ip_cible;
        std::string m_ip_recu;
        std::string m_message;
    
    public:    
        // Ascenseurs
        void setmessage(std::string message);  
        std::string getmessage(); 
        void setvaleur(std::string valeur);  
        std::string getvaleur();
        void set_ip_recu(std::string ip_recu);  
        std::string get_ip_recu();

        // Méthodes 
        mainsocket();
        mainsocket(int m_port_ecoute);
        void recepteur();  
        void envoie(std::string m_ip_cible);
};

#endif 

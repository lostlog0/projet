#ifndef socket_hpp
#define socket_hpp

#include <iostream>
#include <string>

class mainsocket
{
    protected:
        int m_port_ecoute;
        std::string m_valeur;
        std::string m_ip_cible;
        std::string m_ip_recu;
        std::string m_message;

    public:

        mainsocket(int m_port_ecoute);
        std::string setmessage(std::string m_message);
        std::string getmessage();
        std::string setvaleur(std::string m_valeur);
        std::string getvaleur();
        std::string setip_recu(std::string m_ip_recu);
        std::string getip_recu();
        void recepteur();
        void envoie(std::string m_ip_cible);


};

#endif

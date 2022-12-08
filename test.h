#ifndef test_h
#define test_h

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
        mainsocket();
        mainsocket(int m_port_ecoute);
        void setmessage(std::string m_message);
        std::string getmessage();
        std::string getvaleur();
        void setvaleur(std::string valeur);
        std::string getip_recu();
        void setip_recu(std::string ip_recu);
        void recepteur();
        void envoie();
};

#endif

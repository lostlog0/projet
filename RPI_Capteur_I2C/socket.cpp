#include "socket.hpp"

using namespace std;

    // Constructeur
mainsocket::mainsocket(int port_ecoute)
{
    m_port_ecoute = port_ecoute;
}
    // Assenseurs
void mainsocket::setmessage(string message)
{
    m_message = message;
}
string mainsocket::getmessage()
{
    return m_message;
}

void mainsocket::setvaleur(string valeur)  
{
    m_valeur = valeur;
}
string mainsocket::getvaleur()
{
    return m_valeur;
}
void mainsocket::set_ip_recu(string ip_recu)
{
    m_ip_recu = ip_recu;
}
string mainsocket::get_ip_recu()
{
    return m_ip_recu;
}
    // Méthodes
void mainsocket::recepteur()
{  
   typedef struct sockaddr SOCKADDR;

    struct in_addr
        {
            std::string IN_ADDR;
        };
    
    int sock = socket(AF_INET,SOCK_DGRAM,0);// création de la socket
                                            // AF_INET sert a définir l'IPv4
                                            // SOCK_STREAM sert a préciser que nous utilison udp
   struct sockaddr_in Ssin = {0};
   
 
    Ssin.sin_addr.s_addr = htonl(INADDR_ANY);       //initialisation de sin
    Ssin.sin_family = AF_INET;               //on définis la famille utilisé ici l'IPv4
    Ssin.sin_port = htons(m_port_ecoute);      // on précise le port utilisé 

    bind(sock, (SOCKADDR *)&Ssin, sizeof Ssin);  //bin lie une addresse locale a une socket
                                                //sock se parametre sert a idantifier si une socket est non lié 
                                                //le pointeur point vers sockaddr
                                                //ce parametre sert a définir la longueur d'octets
    
    struct sockaddr_in sin = {0};
    
    unsigned int size_sin = sizeof(sin);
    char data[128];    // on initialise une variable de type char qui sock notre valeur reçue
    recvfrom(sock,data,sizeof(data),0,(SOCKADDR*)&sin, &size_sin); // cette commande permet de réceptionner notre valeur 
    m_valeur = data; //ici nous convertit sous la variable de type char en type string
    close(sock);
}

void mainsocket::envoie(string ip_cible)
{
    m_ip_cible = ip_cible;
    typedef struct sockaddr SOCKADDR;

    struct in_addr
        {
            std::string IN_ADDR;
        };

    int sock = socket(AF_INET,SOCK_DGRAM,0); // création de la socket
                                            // AF_INET sert a définir l'IPv4
                                            // SOCK_STREAM sert a préciser que nous utilison udp
   struct sockaddr_in sin = {0};
    
    const char* str = m_ip_cible.c_str();
    sin.sin_addr.s_addr = inet_addr(str);       //initialisation de sin
    sin.sin_family = AF_INET;               //on définis la famille utilisé ici l'IPv4
    sin.sin_port = htons(m_port_ecoute);  
    
    const char* char_message = m_message.c_str(); //ici nous convertissons une variable du type STRING en variable du type CHAR
    sendto (sock,char_message,strlen(char_message),0,(SOCKADDR*)&sin, sizeof sin);// Puis nous envoyons ce message de type char, nous l'envoyons par une variable de type char car la commande accepte seulement les variables de type char
    close(sock);
}


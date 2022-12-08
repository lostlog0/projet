#include <iostream>
#include "socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>

using namespace std;


mainsocket::mainsocket(int port_ecoute)
{
    m_port_ecoute = port_ecoute;
}

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
    char data[128];
    char name[128];
    recvfrom(sock,data,sizeof(data),0,(SOCKADDR*)&sin, &size_sin);
    m_valeur = data;
    gethostname(name,sizeof(name));
    m_ip_recu = name;
    close(sock);
}


void mainsocket::envoie(string m_ip_cible)
{
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

    const char* char_message = m_message.c_str();
    sendto (sock,char_message,strlen(char_message),0,(SOCKADDR*)&sin, sizeof sin);
    close(sock);

}
string mainsocket::setmessage(string message)
{
    m_message = message;
    return " ";
}
string mainsocket::getmessage()
{
    return m_message;
}

string mainsocket::getvaleur()
{
    return m_valeur;
}
string mainsocket::getip_recu()
{
    return m_ip_recu;
}


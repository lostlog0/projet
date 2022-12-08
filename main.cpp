#include "mainwindow.h"
#include "test.h"
#include <QApplication>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[])
{
    while(1){

    sleep (3);
   // socket

    mainsocket socket_recep(9998);
    socket_recep.recepteur();
    string valeur_donnees = socket_recep.getvaleur();
    string ip_recu = socket_recep.getip_recu();

   // affichage

    QApplication a(argc, argv);
    MaFenetre fenetre;
    fenetre.ouvrirDialogue(valeur_donnees, ip_recu);

   //

    fenetre.show();
    int poubelle = a.exec();
}
}
    //return poubelle;


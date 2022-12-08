#include "mainwindow.h"

using namespace std;
MaFenetre::MaFenetre() : QWidget()
{
    setFixedSize(500,150);
    m_boutonDialogue = new QPushButton("Ouvrir la boite de Dialogue",this);
    m_boutonDialogue->move(40,50);

    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(slotOpenUrl()));
}

void MaFenetre::ouvrirDialogue(string valeur, string ip_recu)
{

    QString fichier = "/home/ubuntu/mafenetre/logs.txt";

    QFile file(fichier); // Appel du constructeur de la classe QFile

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append), "a") {
    // Si l'ouverture du fichier en écriture à réussie

    // écrire dans le fichier
    file.write(valeur.c_str());
    file.write("\n");
    file.write(ip_recu.c_str());
    file.write("\n");

    // Fermer le fichier
    file.close();
}
}
void MaFenetre::slotOpenUrl() {

    QDesktopServices::openUrl(QUrl("/home/ubuntu/mafenetre/logs.txt"));

}

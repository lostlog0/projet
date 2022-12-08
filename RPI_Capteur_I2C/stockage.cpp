#include "stockage.hpp"

using namespace std;

    // Constructeur
Stockage::Stockage(){}

Stockage::Stockage(string date_traite, string valeur_traite)
{
    m_date_traite = date_traite;
    m_valeur_traite = valeur_traite;
}
    // Assenseurs
string Stockage::getEcriture()
{
    return m_ecriture;
}

void Stockage::setEcriture(string ecriture)
{
    m_ecriture = ecriture;
}

    // Méthodes
void Stockage::imbrication_date_valeur()
{
    m_ecriture = m_date_traite + m_valeur_traite + "\nRPI_1";
}

void Stockage::ecriture_log() const
{
    string const Fichier("log.txt");
    ofstream monlog(Fichier.c_str(),ios::app);
    if(monlog)
    {
        monlog<<m_ecriture<<endl;
    }
    else
    {
        cout<<"Erreur: Impossible d'ouvir le fichier."<< endl;
    }
}

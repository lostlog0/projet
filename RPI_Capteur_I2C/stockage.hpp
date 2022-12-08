#ifndef stockage_hpp
#define stockage_hpp

#include <string>
#include <fstream>
#include <iostream>

class Stockage
{
    // Attributs
private:
    std::string m_date_traite;
    std::string m_valeur_traite;
    std::string m_ecriture;
    
public:
    // Ascenseurs
    std::string getEcriture();
    void setEcriture(std::string ecriture);
    
    // Méthodes
    Stockage();
    Stockage(std::string date_traite, std::string valeur_traite);
    void imbrication_date_valeur();
    void ecriture_log() const;

};
#endif

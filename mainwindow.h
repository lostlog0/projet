#ifndef MAFENETRE_H
#define MAFENETRE_H

#include<QInputDialog>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QFontDialog>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QDesktopServices>
#include <QColorDialog>
#include <QFileDialog>
#include <QUrl>

class MaFenetre : public QWidget // On hérite de Qwidget (Important)
{
    Q_OBJECT // Permet de créer des signaux et slots personnalisés
public:
    MaFenetre();

public slots:
    void ouvrirDialogue(std::string valeur, std::string ip_recu);
    void slotOpenUrl();

private:
    QPushButton *m_boutonDialogue;
};
#endif // MAFENETRE_H

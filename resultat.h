#ifndef RESULTAT_H
#define RESULTAT_H
#include <qstringlist.h>
#include <QList>

/*
 * \class Resultat
 * \brief representant l'ensemble des resultat relut dans les fichier
 */

class Resultat
{
    private:
    ///List des personnes ayant relut au moins 1 fiche
    QStringList listRelecteur;
    ///List du nombre de relectuer range par personnes
    QList <int>  listTotalRelecture;

public:
    ///Constructeur
    Resultat();
    ///Acces à la list des relecteyr
    QStringList getListRelecteur() const;
    void setListRelecteur(const QStringList &value);
    ///Acces à la list du nombre total de relecteur
    QList<int> getListTotalRelecture() const;
    void setListTotalRelecture(const QList<int> &value);

    ///Ajout un relecteur à la liste
    void addRelecteur(QString relecteur);
    ///Retourne la position d'un relecte dans la liste
    int getPositionReleteur(QString relecteur);
    ///Ajout une fiche au total d'un relecteyr
    void addFicheToRelecteur(int position);
};

#endif // RESULTAT_H

#ifndef RESULTAT_H
#define RESULTAT_H
#include <qstringlist.h>
#include <QList>

/*
 * \class Resultat
 * \brief representant l'ensemble des resultat relut dans les fichier
 */

struct typeErreur
{
	int maj;
	int moy;
	int min;

};
class Resultat
{
    private:
    ///List des personnes ayant relut au moins 1 fiche
    QStringList listRelecteur;
    ///List du nombre de relectuer range par personnes
    QList <int>  listTotalRelecture;
	///List du nombre de temps passe en min
	QList<int> listTotalTime;
	///ListErreur
	QList<typeErreur> listTotalErreur;
	/// List Erreur corrigé
	QList<typeErreur> listTotalCorrErreur;

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
	int getPositionRelecteur(QString relecteur);
    ///Ajout une fiche au total d'un relecteyr
	void addFicheToRelecteur(int position);
	QList<int> getListTotalTime() const;
	void addTime(QString relecteur, int time);
	QList<typeErreur> getListErreur() const;
	QList<typeErreur> getListErreurCorr() const;
	void addErreur(QString relecteur, typeErreur value);
	void addErreurCorrige(QString relecteur, typeErreur value);
};

#endif // RESULTAT_H

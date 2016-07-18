#include "resultat.h"
#include <QDebug>

QStringList Resultat::getListRelecteur() const
{
    return listRelecteur;
}

void Resultat::setListRelecteur(const QStringList &value)
{
    listRelecteur = value;
}

QList<int> Resultat::getListTotalRelecture() const
{
    return listTotalRelecture;
}

QList<int> Resultat::getListTotalTime() const
{
	return listTotalTime;
}

QList<typeErreur> Resultat::getListErreur() const
{
	return listTotalErreur;
}
/// List Erreur corrigé
QList<typeErreur> Resultat::getListErreurCorr() const
{
	return listTotalCorrErreur;
}

void Resultat::setListTotalRelecture(const QList<int> &value)
{
    listTotalRelecture = value;
}

void Resultat::addRelecteur(QString relecteur)
{
    if(!listRelecteur.contains(relecteur))
    {
	qDebug()<<"Relecteur="<<relecteur;
	listRelecteur.insert(listRelecteur.count()+1,relecteur);
	listTotalRelecture.insert(listTotalRelecture.count()+1,1);
	listTotalTime.insert(listTotalTime.count()+1,0);
	struct typeErreur initErreur;
	initErreur.maj=0;
	initErreur.moy=0;
	initErreur.min=0;
	listTotalErreur.insert(listTotalErreur.count()+1,initErreur);
	listTotalCorrErreur.insert(listTotalCorrErreur.count()+1,initErreur);
    }
    else
    {
		addFicheToRelecteur(getPositionRelecteur(relecteur));
    }
}

int Resultat::getPositionRelecteur(QString relecteur)
{
    for(int i=0;i<listRelecteur.count();i++)
    {
        if(relecteur.compare(listRelecteur.at(i))==0)
        {
            return i;
        }
    }
    return -1; ///Pas de relecteur trouve
}

void Resultat::addFicheToRelecteur(int position)
{

    int valeur=listTotalRelecture.at(position);
	listTotalRelecture.replace(position,valeur+1);

	for(int i=0;i<listRelecteur.count();i++)
	{
		qDebug()<<"Position "<<i<<"Valeur "<<listTotalRelecture.at(i)
			   <<"Time"<<listTotalTime.at(i);
	}
}

Resultat::Resultat()
{

}

void Resultat::addTime(QString relecteur,int time)
{
	int position=getPositionRelecteur(relecteur);
	int oldValue=listTotalTime.at(position);
	listTotalTime.replace(position,oldValue+time);
}

void Resultat::addErreur(QString relecteur,typeErreur value)
{
	struct typeErreur oldValue;
	int position=getPositionRelecteur(relecteur);
	oldValue=listTotalErreur.at(position);
	struct typeErreur newValue;

	newValue.maj=value.maj+oldValue.maj;
	newValue.moy=value.moy+oldValue.moy;
	newValue.min=value.min+oldValue.min;

	listTotalErreur.replace(position,newValue);


}

void Resultat::addErreurCorrige(QString relecteur,typeErreur value)
{
	struct typeErreur oldValue;
	int position=getPositionRelecteur(relecteur);
	oldValue=listTotalCorrErreur.at(position);
	struct typeErreur newValue;

	newValue.maj=value.maj+oldValue.maj;
	newValue.moy=value.moy+oldValue.moy;
	newValue.min=value.min+oldValue.min;

	listTotalCorrErreur.replace(position,newValue);
}

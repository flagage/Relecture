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

void Resultat::setListTotalRelecture(const QList<int> &value)
{
    listTotalRelecture = value;
}

void Resultat::addRelecteur(QString relecteur)
{
    if(!listRelecteur.contains(relecteur))
    {
    listRelecteur.append(relecteur);
    listTotalRelecture.append(1);
    }
    else
    {
        qDebug()<<"Relecteur="<<relecteur;
        qDebug()<<getPositionReleteur(relecteur);
        addFicheToRelecteur(getPositionReleteur(relecteur));
    }
}

int Resultat::getPositionReleteur(QString relecteur)
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
    qDebug()<<"Position ="<<position;
    int valeur=listTotalRelecture.at(position);
    qDebug()<<"Valeur "<<valeur;
    listTotalRelecture.insert(position,valeur+1);
}

Resultat::Resultat()
{

}


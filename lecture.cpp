#include "lecture.h"



Lecture::Lecture(QString fileName)
{
    nomFichier=fileName;
    xlsx.setPackageName(nomFichier);

}

QString Lecture::getRelecteur()
{
    QStringList ListReviewer=xlsx.read("A3").toString().split(":");
    QString readReviewer=ListReviewer.at(1);
	return readReviewer;
}

int Lecture::getTime()
{
	QString timeRead=xlsx.read("B6").toString();
	qDebug()<<"B6"<<timeRead;
	return timeRead.toInt();
}

typeErreur Lecture::getErreur()
{
	 typeErreur erreur;

	erreur.maj=xlsx.read("C8").toInt();
	erreur.moy=xlsx.read("C9").toInt();
	erreur.min=xlsx.read("C10").toInt();
	return erreur;
}

typeErreur Lecture::getErreurCorr()
{
	 typeErreur erreur;

	erreur.maj=xlsx.read("C12").toInt();
	erreur.moy=xlsx.read("C13").toInt();
	erreur.min=xlsx.read("C14").toInt();
	return erreur;
}


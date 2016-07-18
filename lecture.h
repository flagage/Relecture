#ifndef LECTURE_H
#define LECTURE_H
#include <QString>
#include "xlsxdocument.h"
#include <QDebug>
#include "resultat.h"

class Lecture
{
private:
    QString nomFichier;
    QXlsx::Document xlsx;
public:
    Lecture(QString fileName);
	QString getRelecteur();
	int getTime();
	typeErreur getErreur();
	typeErreur getErreurCorr();
};

#endif // LECTURE_H

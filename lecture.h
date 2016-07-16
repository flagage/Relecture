#ifndef LECTURE_H
#define LECTURE_H
#include <QString>
#include "xlsxdocument.h"
#include <QDebug>

class Lecture
{
private:
    QString nomFichier;
    QXlsx::Document xlsx;
public:
    Lecture(QString fileName);
    QString getRelecteur();
};

#endif // LECTURE_H

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
    qDebug()<<readReviewer;
    return readReviewer;
}

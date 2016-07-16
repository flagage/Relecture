#include <QCoreApplication>
#include "lecture.h"
#include "resultat.h"
#include <QTextStream>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);


    QDir dir(argv[1]);
      qDebug()<<argv[1];
    QStringList Filtre;
    Filtre << "*.xlsx";
    dir.setNameFilters(Filtre);
    QStringList listFile=dir.entryList();
      qDebug()<<"count="<<listFile.count();
    Resultat result;
    for(int i=0;i<listFile.count();i++)
    {
    QString file=argv[1];
    file=file+"\\"+listFile.at(i);
    qDebug()<<file;
    Lecture lecture(file);
    result.addRelecteur(lecture.getRelecteur());
    }

    QTextStream out(stdout);
    for(int i=0;i<result.getListRelecteur().count();i++)
    {
        out<<i<<result.getListRelecteur().at(i)<<" "
        <<result.getListTotalRelecture().at(i)<<endl;
    }

    return a.exec();
}


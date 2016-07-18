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
    Lecture lecture(file);
	QString strRelecteur=lecture.getRelecteur();
	result.addRelecteur(strRelecteur);
	result.addTime(strRelecteur,lecture.getTime());
	result.addErreur(strRelecteur,lecture.getErreur());
	result.addErreurCorrige(strRelecteur,lecture.getErreurCorr());
    }

    QTextStream out(stdout);
    for(int i=0;i<result.getListRelecteur().count();i++)
    {
        out<<i<<result.getListRelecteur().at(i)<<" "
		<<result.getListTotalRelecture().at(i)<< " "
		<<result.getListTotalTime().at(i)<<" "
		<<result.getListErreur().at(i).maj<<","<<result.getListErreur().at(i).moy<<","<<
		  result.getListErreur().at(i).min<<" "
		<<result.getListErreurCorr().at(i).maj<<","<<result.getListErreurCorr().at(i).moy<<","<<
		  result.getListErreurCorr().at(i).min<<
		  endl;
    }

    return a.exec();
}


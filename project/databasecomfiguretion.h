#ifndef DATABASECOMFIGURETION_H
#define DATABASECOMFIGURETION_H

//#include <QSql>
#include <QDateTime>
#include <QDate>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlQuery>

class databasecomfiguretion
{
public:


    databasecomfiguretion();
    qint32 getdatasim();
    qint32 getsize();
//    qint32 Room[10] = {1,1,1,1,1,1,1,1,1,1};        //Room Number
//    qint32 Date[10] = {1,1,3,3,4,5,7,7,7,4};        //Date
//    qint32 SHH[40] = {13,13,13,13,13,13,13,13,13,13};         //HH Start
 //   qint32 EHH[40] = {21,21,21,21,21,21,21,21,21,21};         //HH End
    qint32 SMM[40];         //MM Start
    qint32 EMM[40];         //MM End
    qint32 Size;

public slots:
   // void getdbdata(int Room_No);


private:
    QSqlDatabase db;
    QString dsn;

};

#endif // DATABASECOMFIGURETION_H

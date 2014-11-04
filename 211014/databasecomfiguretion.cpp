#include "databasecomfiguretion.h"
#include <QList>

databasecomfiguretion::databasecomfiguretion()
{
    QString servername = "192.168.1.200";   //Satabase Server
    QString dbname = "project";             //Database Name
    QString user = "sa";                   //Database User
    QString password = "0000";              //Database Password
    qint32 Room[40];        //Room Number
    qint32 Date[40];        //Date
    qint32 SHH[40];         //HH Start
    qint32 EHH[40];         //HH End
    qint32 SMM[40];         //MM Start
    qint32 EMM[40];         //MM End


    qint32 NDate;           //Date Now
    qint32 NHH;             //HH Now
    qint32 NMM;             //MM Now
/*
    //set Database Connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;").arg(servername).arg(dbname).arg(user).arg(password);
    db.setDatabaseName(dsn);
    db.open();
    //printf(db.lastError());
    //Sql Query
    QSqlQuery qry;
    if(qry.exec("select Room.r_id as Room , times.t_date as Date,times.t_h_start as SHH,times.t_h_end as EHH,times.t_m_start as SMM,times.t_m_end as EMM  from Room JOIN Course 	ON Room.r_id = Course.c_room JOIN Times	ON Course.c_time = Times.t_id order by Room asc , SHH asc"))
            {   int i = 0;
        int b = 0;
                int y = qry.numRowsAffected();
                printf("y = %d  i = %d \n",y,i);
                while(i<y)
                {
                    qry.next();
                    printf("db query \n");

                    NHH = QTime::currentTime().toString("HH").toInt();
                    NMM = QTime::currentTime().toString("MM").toInt();
                    NDate = QDate::currentDate().dayOfWeek();

                    Room[i]=qry.value(0).toInt();
                    Date[i]=qry.value(1).toInt();
                    SHH[i]=qry.value(2).toInt();
                    EHH[i]=qry.value(3).toInt();
                    SMM[i]=qry.value(4).toInt();
                    EMM[i]=qry.value(5).toInt();

                   // printf("room %d ",Room[i]);
                   // printf("date %d start %d END %d  now %d  %d\n",Date[i],SHH[i],EHH[i],NDate,NHH);
                   // qDebug() << NHH;


                    i+=1;

                }
        }
            printf("exit db\n");
            db.close();
*/
}

/*QList<qint32> databasecomfiguretion::getdata(){
    qint32 Room[40];        //Room Number
    qint32 Date[40];        //Date
    qint32 SHH[40];         //HH Start
    qint32 EHH[40];         //HH End
    qint32 SMM[40];         //MM Start
    qint32 EMM[40];         //MM End
    qint32 test[40];
    //set Database Connection
    //Sql Query
    QSqlQuery qry;
    if(qry.exec("select Room.r_id as Room , times.t_date as Date,times.t_h_start as SHH,times.t_h_end as EHH,times.t_m_start as SMM,times.t_m_end as EMM  from Room JOIN Course 	ON Room.r_id = Course.c_room JOIN Times	ON Course.c_time = Times.t_id order by Room asc , SHH asc"))
            {   int i = 0;
                int y = qry.numRowsAffected();
                printf("y = %d  i = %d \n",y,i);
                while(i<y)
                {
                    qry.next();

                    NHH = QTime::currentTime().toString("HH").toInt();
                    NMM = QTime::currentTime().toString("MM").toInt();
                    NDate = QDate::currentDate().dayOfWeek();

                    Room[i]=qry.value(0).toInt();
                    Date[i]=qry.value(1).toInt();
                    SHH[i]=qry.value(2).toInt();
                    EHH[i]=qry.value(3).toInt();
                    SMM[i]=qry.value(4).toInt();
                    EMM[i]=qry.value(5).toInt();

                   // printf("room %d ",Room[i]);
                   // printf("date %d start %d END %d  now %d  %d\n",Date[i],SHH[i],EHH[i],NDate,NHH);
                   // qDebug() << NHH;


                    i+=1;

                }
        }
        //test[0,1,2,3,4,5] = Room,Date,SHH,EHH,SMM,EMM;
            printf("exit db\n");
            db.close();
           return(Room);
}
*/
qint32 databasecomfiguretion::getdatasim(){
    qint32 b[10] = {1,2,3,4,5,6,7,8,9,10};
        printf("Database read form simmulate");
        return 11;
                }
qint32 databasecomfiguretion::getsize(){
    return 10;
}


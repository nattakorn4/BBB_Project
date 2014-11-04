#include "timeclock.h"


timeclock::timeclock()
{
}

QTime timeclock::getTime()
{
    QTime time = QTime::currentTime();
    //printf("getTime");printf(time);
    return time;
}

QString timeclock::getTimeString()
{


    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if ((time.second() % 2) == 0){
        text[2] = ' ';
        text[5] = ' ';
     }

    //printf("getTimeString");printf(text);
    return text;
}

qint32 timeclock::getHH(){
    QTime time = QTime::currentTime();
    QString text = time.toString();

    QString H0 = text.at(0);
    QString H1 = text.at(1);
    qint32 HH0 = H0.toInt();
    qint32 HH1 = H1.toInt();
    qint32 HH = (HH0*10)+HH1;
    //printf("getHH %d /n",HH);
    return HH;
}
qint32 timeclock::getMM(){
    QTime time = QTime::currentTime();
    QString text = time.toString();

    QString M0 = text.at(3);
    QString M1 = text.at(4);
    qint32 MM0 = M0.toInt();
    qint32 MM1 = M1.toInt();
    qint32 MM = (MM0*10)+MM1;
    //printf("getMM %d\n",MM);
    return MM;

}

qint32 timeclock::getDate(){

    qint32 NDate = QDate::currentDate().dayOfWeek();
    //printf("getDate %d\n",NDate);
    return NDate;

}

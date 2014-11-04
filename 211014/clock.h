#ifndef CLOCK_H
#define CLOCK_H

#include <QTime>
#include <labelshowtime.h>

class clock
{

public:
    clock();
    QTime getTime();
    QString getTimeString();
    qint32 getHH();
    qint32 getMM();
    qint32 getDate();

private:




};


#endif // CLOCK_H

#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include <QTime>
#include <labelshowtime.h>

class timeclock
{

public:
    timeclock();
    QTime getTime();
    QString getTimeString();
    qint32 getHH();
    qint32 getMM();
    qint32 getDate();

private:




};


#endif // CLOCK_H

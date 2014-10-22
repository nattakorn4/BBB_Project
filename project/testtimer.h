#ifndef TESTTIMER_H
#define TESTTIMER_H

#include <QTimer>
#include <QTime>

class testtimer : public QObject
{
     Q_OBJECT
public:
    testtimer();
    QTimer *timer;

public slots:
    void test1();
};

#endif // TESTTIMER_H

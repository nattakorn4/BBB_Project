#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QTimer>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    QTimer *timer;

public slots:
    void test1();
};

#endif // CONTROLLER_H

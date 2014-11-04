#ifndef LABELSHOWTIME_H
#define LABELSHOWTIME_H

#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QLCDNumber>

class labelshowtime : public QLabel
{
    Q_OBJECT
public:
    explicit labelshowtime(QWidget *parent = 0);

signals:


public slots:
    void ShowTime();
};

#endif // LABELSHOWTIME_H

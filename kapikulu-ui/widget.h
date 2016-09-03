#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFile>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *timeouter;
    QTimer *timeouter_2;
//    QFile *ttyArduino;


//signals:
//    void trigReadTTY();
    void picTrig();

private slots:
//    void readTTY();
    void piccer();


};

#endif // WIDGET_H

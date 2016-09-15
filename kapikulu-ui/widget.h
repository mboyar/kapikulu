#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QPainter>


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

    void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        painter.setPen(Qt::black);
        //... Need an appropriate call to painter.translate() for this to work properly
        painter.rotate(90);
        painter.drawText(QPoint(0,0), "_text");
    }

//signals:
//    void trigReadTTY();
    void picTrig();

private slots:
//    void readTTY();
    void piccer();




};

#endif // WIDGET_H

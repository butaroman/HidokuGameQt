#include "mainwindowpainter.h"
#include "ui_mainwindowpainter.h"

MainWindowPainter::MainWindowPainter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowPainter)
{
    ui->setupUi(this);


}

MainWindowPainter::~MainWindowPainter()
{
    delete ui;
}
void MainWindowPainter::paintEvent(QPaintEvent *e){
    int i,sx,sy,gcx,gcy;
    char c;
    painter = new QPainter(this);
    sx=this->width();
    sy=this->height();

    gcx=sx/10;
    gcy=sy/10;
    painter->setPen(QPen(Qt::black,2,Qt::SolidLine));
   // painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", 12));

    for(i=1;i<10;i++){

        painter->drawLine(0,i*gcy,sx,i*gcy);
        //sprintf(&c,"%d",10-i);
        //painter->drawText(gcx/4,i*gcy-gcy/1,18,18,1,&c,0);

        painter->drawLine(gcx*i,0,gcx*i,sy);
       // sprintf(&c,"%d",i);
        //painter->drawText(gcx*i+gcx/4,sy-25,18,18,1,&c,0);
    }



    painter->end();
}

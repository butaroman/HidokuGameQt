#ifndef MAINWINDOWPAINTER_H
#define MAINWINDOWPAINTER_H

#include <QMainWindow>
#include <QtGui/QPainter>
#include <stdio.h>
namespace Ui {
class MainWindowPainter;
}

class MainWindowPainter : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowPainter(QWidget *parent = 0);
    ~MainWindowPainter();

private:
    Ui::MainWindowPainter *ui;
    QPainter *painter;
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOWPAINTER_H

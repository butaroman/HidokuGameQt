#ifndef MVSCENE_H
#define MVSCENE_H

#include <QGraphicsScene>

class MvScene : public QGraphicsScene
{
public:
    MvScene();
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void keyPressEvent(QKeyEvent * keyEvent);
private:
    QGraphicsPixmapItem * worker;
    void makeWalls();
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);
    void placeBox(float x, float y);
    void setBoxes();

#endif // MVSCENE_H

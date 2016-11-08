#include "mvscene.h"

MvScene::MvScene()
{
}
void MvScene::makeWalls()
{
    float walls[11][4] = {{0, 0, 25, 245}, {25, 0, 425, 25}, {425, 0, 25, 245}, ...};
    QBrush brush(QColor(255, 255, 255), QPixmap("wall.jpg"));
    QPen pen(Qt::NoPen);
    for (int i = 0; i < 11; i++) {
        QGraphicsItem * item =
        addRect(QRectF(walls[i][0], walls[i][1], walls[i][2], walls[i][3]), pen, brush);
        item->setData(0, "Wall");
    }
}

void MvScene::keyPressEvent(QKeyEvent * keyEvent)
{
    QPointF np;
    np.setX(0);
    np.setY(0);
    switch (keyEvent->key()) {
        case Qt::Key_Left:
            np.setX(-10);
            break;
        case Qt::Key_Right:
            np.setX(10);
            break;
        case Qt::Key_Up:
            np.setY(-10);
            break;
        case Qt::Key_Down:
            np.setY(10);
            break;
    }
    worker->translate(np.x(), np.y());
    QGraphicsItem * obstacle = itemCollidesWith(worker);
    if (obstacle) {
        if (obstacle->data(0) == "Wall") {
            worker->translate(-np.x(), -np.y());
            printf("Hello wall!\n");
        }
        else
        if (obstacle->data(0) == "Box") {
            obstacle->translate(np.x(), np.y());
            if (itemCollidesWith(obstacle) || itemCollidesWith(worker)) {
                obstacle->translate(-np.x(), -np.y());
                worker->translate(-np.x(), -np.y());
                printf("Cannot move!\n");
            }
        }
    }
}

QGraphicsItem * MvScene::itemCollidesWith(QGraphicsItem * item)

    {
    QList<QGraphicsItem *> collisions = collidingItems(item);
    foreach (QGraphicsItem * it, collisions) {

                if (it == item)

                 continue;
                return it;

    }
        return NULL;

    }

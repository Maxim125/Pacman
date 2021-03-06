#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include <QKeyEvent>
#include "Maze.h"
class Position;
class Size;
class QPainter;
class QPixmap;
class Player : public QObject
{
 Q_OBJECT
private:
        static Position *startPosition;
        static Position *pos;
        Maze * maze;
        QPixmap  *heroSprite;
        int health;
        int speed;
        static int reqDirection;
        static int direction;
        int dx;
        int dy;
public:
     Player(Maze *maze, QObject *parent = 0);
    void draw(QPainter *painter);
    void update();
    static const Position * playerPosition();
    bool move(int rDirection);
    bool alive();
    void addMoney(int kesh);
    void setOnStartPosition();
    bool levelComplete();
    static void initPosition(int x, int y);
//    bool event (QEvent *Event);
    static void setReqDirection(int direct);
    const Position & getPosition();
    virtual ~Player();
};

#endif // PLAYER_H
#ifndef STUDY_H
#define STUDY_H

#include <QImage>
#include <QRect>
#include "Specials.h"

class Study : public Specials{
public:
    Study(int,int);
    ~Study();
public:
    void resetState();
    void autoMove();
    void moveUp(int);
    void moveDown(int);
    void moveLeft(int);
    void moveRight(int);
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    bool isCaught();
    void setCaught(bool);
    void setLetter(int);
    double getLetter();
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
private:
    int xdir;
    int ydir;
    int accx;
    int accy;
    bool stuck;
    QImage image;
    QRect rect;
    int position;
    bool caught;
    double letter;
};

#endif // STUDY_H

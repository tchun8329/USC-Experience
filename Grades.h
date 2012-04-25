#ifndef GRADES_H
#define GRADES_H

#include <QImage>
#include <QRect>
#include "Object.h"

class Grades : public Object{
public:
    Grades(int,int);
    ~Grades();
public:
    void resetState();
    void autoMove();
    void moveUp(int);
    void moveDown(int);
    void moveLeft(int);
    void moveRight(int);
    void setXDir(int);
    void setYDir(int);
    virtual int getXDir() = 0;
    virtual int getYDir() = 0;
    bool isCaught();
    void setCaught(bool);
    void setLetter(int);
    virtual double getLetter() = 0;
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
};

#endif // GRADES_H

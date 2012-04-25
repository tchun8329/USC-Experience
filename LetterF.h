#ifndef LETTERF_H
#define LETTERF_H

#include <QImage>
#include <QRect>
#include "Grades.h"

class LetterF : public Grades{
public:
    LetterF(int,int);
    ~LetterF();
public:
    void resetState();
    void autoMove();
    void moveUp(int);
    void moveDown(int);
    void moveLeft(int);
    void moveRight(int);
    void setXDir(int);
    void setYDir(int);
    void setXAcc(double);
    void setYAcc(double);
    int getXDir();
    int getYDir();
    bool isCaught();
    void setCaught(bool);
    void setLetter(int);
    double getLetter();
    double getXAcc();
    double getYAcc();
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
private:
    double xdir;
    double ydir;
    double accx;
    double accy;
    bool stuck;
    QImage image;
    QRect rect;
    int position;
    bool caught;
    double letter;
};

#endif // LETTERF_H

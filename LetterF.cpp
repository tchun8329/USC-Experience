#include "LetterF.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

LetterF::LetterF(int x, int y) : Grades(x,y){
    //use the x and y for the types of Letter F
    image.load(":/LetterF.png");
    xdir = 0.0;
    ydir = 0.0;
    accx = 0.0;
    accy = 0.0;
    rect = image.rect();
    rect.setHeight(16);
    rect.setWidth(16);
    letter = 0;
    caught = false;
    resetState();
}

LetterF::~LetterF(){
    std::cout << ("Letter F deleted\n");
}

void LetterF::autoMove(){
    rect.translate(xdir,ydir);
    if(rect.left() < 215 && rect.right() > 215)
        xdir = -xdir;
    if(rect.right() > 660 && rect.left() < 660)
        xdir = -xdir;
    if(rect.top() < 245 && rect.bottom() > 245)
        ydir = -ydir;
    if(rect.bottom() > 550 && rect.top() < 550)
        ydir = -ydir;
    int coeff = 0 + qrand() % 3;
    if (rect.center().x() != accx)
        xdir = xdir + (coeff*accx - rect.center().x())/1200;
    if (rect.center().y() != accy)
        ydir = ydir + (coeff*accy - rect.center().y())/1200;
    if (xdir > 2.5)
        xdir = 2.5;
    if (xdir < -2.5)
        xdir = -2.5;
    if (ydir > 2.5)
        ydir = 2.5;
    if (ydir < -2.5)
        ydir = -2.5;
}

void LetterF::setXAcc(double x){
    accx = x;
}

void LetterF::setYAcc(double y){
    accy = y;
}

double LetterF::getXAcc(){
    return accx;
}

double LetterF::getYAcc(){
    return accy;
}

void LetterF::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void LetterF::setLetter(int let){
    letter = let;
}

double LetterF::getLetter(){
    return letter;
}

void LetterF::moveDown(int down){
    rect.moveBottom(down);
}

void LetterF::moveLeft(int left){
    rect.moveLeft(left);
}

void LetterF::moveRight(int right){
    rect.moveRight(right);
}

void LetterF::moveUp(int up){
    rect.moveTop(up);
}

void LetterF::setXDir(int x){
    xdir = x;
}

void LetterF::setYDir(int y){
    ydir = y;
}

int LetterF::getXDir(){
    return xdir;
}

int LetterF::getYDir(){
    return ydir;
}

QRect LetterF::getRect(){
    return rect;
}

void LetterF::setRect(QRect rct){
    rect = rct;
}

QImage & LetterF::getImage(){
    return image;
}

bool LetterF::isCaught(){
    return caught;
}

void LetterF::setCaught(bool cght){
    caught = cght;
}

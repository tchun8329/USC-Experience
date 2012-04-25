#include "Sleep.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Sleep::Sleep(int x, int y) : Specials(x,y){
    //use the x and y for the types of Sleep
    accx = 0;
    accy = 0;
    image.load(":/Sleep.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 4.0;
    caught = false;
    resetState();
}

Sleep::~Sleep(){
    std::cout << ("Sleep deleted\n");
}

void Sleep::autoMove(){
    if(xdir == 0 && ydir == 0){
        xdir = -2 + qrand() % 4;
        ydir = -2 + qrand() % 4;
    }
    rect.translate(xdir,ydir);
    if(rect.left() < 215 && rect.right() > 215)
        xdir = -xdir;
    if(rect.right() > 660 && rect.left() < 660)
        xdir = -xdir;
    if(rect.top() < 245 && rect.bottom() > 245)
        ydir = -ydir;
    if(rect.bottom() > 550 && rect.top() < 550)
        ydir = -ydir;

}

void Sleep::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void Sleep::setLetter(int let){
    letter = let;
}

double Sleep::getLetter(){
    return letter;
}

void Sleep::moveDown(int down){
    rect.moveBottom(down);
}

void Sleep::moveLeft(int left){
    rect.moveLeft(left);
}

void Sleep::moveRight(int right){
    rect.moveRight(right);
}

void Sleep::moveUp(int up){
    rect.moveTop(up);
}

void Sleep::setXDir(int x){
    xdir = x;
}

void Sleep::setYDir(int y){
    ydir = y;
}

int Sleep::getXDir(){
    return xdir;
}

int Sleep::getYDir(){
    return ydir;
}

QRect Sleep::getRect(){
    return rect;
}

void Sleep::setRect(QRect rct){
    rect = rct;
}

QImage & Sleep::getImage(){
    return image;
}

bool Sleep::isCaught(){
    return caught;
}

void Sleep::setCaught(bool cght){
    caught = cght;
}





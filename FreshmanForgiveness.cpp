#include "FreshmanForgiveness.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

FreshmanForgiveness::FreshmanForgiveness(int x, int y) : Specials(x,y){
    //use the x and y for the types of FreshmanForgiveness
    accx = 0;
    accy = 0;
    image.load(":/FreshmanForgiveness.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 4.0;
    caught = false;
    resetState();
}

FreshmanForgiveness::~FreshmanForgiveness(){
    std::cout << ("FreshmanForgiveness deleted\n");
}

void FreshmanForgiveness::autoMove(){
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

void FreshmanForgiveness::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void FreshmanForgiveness::setLetter(int let){
    letter = let;
}

double FreshmanForgiveness::getLetter(){
    return letter;
}

void FreshmanForgiveness::moveDown(int down){
    rect.moveBottom(down);
}

void FreshmanForgiveness::moveLeft(int left){
    rect.moveLeft(left);
}

void FreshmanForgiveness::moveRight(int right){
    rect.moveRight(right);
}

void FreshmanForgiveness::moveUp(int up){
    rect.moveTop(up);
}

void FreshmanForgiveness::setXDir(int x){
    xdir = x;
}

void FreshmanForgiveness::setYDir(int y){
    ydir = y;
}

int FreshmanForgiveness::getXDir(){
    return xdir;
}

int FreshmanForgiveness::getYDir(){
    return ydir;
}

QRect FreshmanForgiveness::getRect(){
    return rect;
}

void FreshmanForgiveness::setRect(QRect rct){
    rect = rct;
}

QImage & FreshmanForgiveness::getImage(){
    return image;
}

bool FreshmanForgiveness::isCaught(){
    return caught;
}

void FreshmanForgiveness::setCaught(bool cght){
    caught = cght;
}




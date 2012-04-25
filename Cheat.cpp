#include "Cheat.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Cheat::Cheat(int x, int y) : Specials(x,y){
    //use the x and y for the types of Cheat
    accx = 0;
    accy = 0;
    image.load(":/Cheat.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 4.0;
    caught = false;
    resetState();
}

Cheat::~Cheat(){
    std::cout << ("Cheat deleted\n");
}

void Cheat::autoMove(){
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

void Cheat::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void Cheat::setLetter(int let){
    letter = let;
}

double Cheat::getLetter(){
    return letter;
}

void Cheat::moveDown(int down){
    rect.moveBottom(down);
}

void Cheat::moveLeft(int left){
    rect.moveLeft(left);
}

void Cheat::moveRight(int right){
    rect.moveRight(right);
}

void Cheat::moveUp(int up){
    rect.moveTop(up);
}

void Cheat::setXDir(int x){
    xdir = x;
}

void Cheat::setYDir(int y){
    ydir = y;
}

int Cheat::getXDir(){
    return xdir;
}

int Cheat::getYDir(){
    return ydir;
}

QRect Cheat::getRect(){
    return rect;
}

void Cheat::setRect(QRect rct){
    rect = rct;
}

QImage & Cheat::getImage(){
    return image;
}

bool Cheat::isCaught(){
    return caught;
}

void Cheat::setCaught(bool cght){
    caught = cght;
}



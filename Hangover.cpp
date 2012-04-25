#include "Hangover.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Hangover::Hangover(int x, int y) : Specials(x,y){
    //use the x and y for the types of Hangover
    accx = 0;
    accy = 0;
    image.load(":/Hangover.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 4.0;
    caught = false;
    resetState();
}

Hangover::~Hangover(){
    std::cout << ("Hangover deleted\n");
}

void Hangover::autoMove(){
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

void Hangover::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void Hangover::setLetter(int let){
    letter = let;
}

double Hangover::getLetter(){
    return letter;
}

void Hangover::moveDown(int down){
    rect.moveBottom(down);
}

void Hangover::moveLeft(int left){
    rect.moveLeft(left);
}

void Hangover::moveRight(int right){
    rect.moveRight(right);
}

void Hangover::moveUp(int up){
    rect.moveTop(up);
}

void Hangover::setXDir(int x){
    xdir = x;
}

void Hangover::setYDir(int y){
    ydir = y;
}

int Hangover::getXDir(){
    return xdir;
}

int Hangover::getYDir(){
    return ydir;
}

QRect Hangover::getRect(){
    return rect;
}

void Hangover::setRect(QRect rct){
    rect = rct;
}

QImage & Hangover::getImage(){
    return image;
}

bool Hangover::isCaught(){
    return caught;
}

void Hangover::setCaught(bool cght){
    caught = cght;
}





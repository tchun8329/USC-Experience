#include "OfficeHours.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

OfficeHours::OfficeHours(int x, int y) : Specials(x,y){
    //use the x and y for the types of OfficeHours
    accx = 0;
    accy = 0;
    image.load(":/OfficeHours.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(16);
    rect.setWidth(16);
    letter = -1.0;
    caught = false;
    resetState();
}

OfficeHours::~OfficeHours(){
    std::cout << ("OfficeHours deleted\n");
}

void OfficeHours::autoMove(){
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

void OfficeHours::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void OfficeHours::setLetter(int let){
    letter = let;
}

double OfficeHours::getLetter(){
    return letter;
}

void OfficeHours::moveDown(int down){
    rect.moveBottom(down);
}

void OfficeHours::moveLeft(int left){
    rect.moveLeft(left);
}

void OfficeHours::moveRight(int right){
    rect.moveRight(right);
}

void OfficeHours::moveUp(int up){
    rect.moveTop(up);
}

void OfficeHours::setXDir(int x){
    xdir = x;
}

void OfficeHours::setYDir(int y){
    ydir = y;
}

int OfficeHours::getXDir(){
    return xdir;
}

int OfficeHours::getYDir(){
    return ydir;
}

QRect OfficeHours::getRect(){
    return rect;
}

void OfficeHours::setRect(QRect rct){
    rect = rct;
}

QImage & OfficeHours::getImage(){
    return image;
}

bool OfficeHours::isCaught(){
    return caught;
}

void OfficeHours::setCaught(bool cght){
    caught = cght;
}





#include "Study.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Study::Study(int x, int y) : Specials(x,y){
    //use the x and y for the types of Study
    accx = 0;
    accy = 0;
    image.load(":/Study.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 4.0;
    caught = false;
    resetState();
}

Study::~Study(){
    std::cout << ("Study deleted\n");
}

void Study::autoMove(){
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

void Study::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void Study::setLetter(int let){
    letter = let;
}

double Study::getLetter(){
    return letter;
}

void Study::moveDown(int down){
    rect.moveBottom(down);
}

void Study::moveLeft(int left){
    rect.moveLeft(left);
}

void Study::moveRight(int right){
    rect.moveRight(right);
}

void Study::moveUp(int up){
    rect.moveTop(up);
}

void Study::setXDir(int x){
    xdir = x;
}

void Study::setYDir(int y){
    ydir = y;
}

int Study::getXDir(){
    return xdir;
}

int Study::getYDir(){
    return ydir;
}

QRect Study::getRect(){
    return rect;
}

void Study::setRect(QRect rct){
    rect = rct;
}

QImage & Study::getImage(){
    return image;
}

bool Study::isCaught(){
    return caught;
}

void Study::setCaught(bool cght){
    caught = cght;
}





#include "ExtraCredit.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

ExtraCredit::ExtraCredit(int x, int y) : Specials(x,y){
    //use the x and y for the types of Extra credit
    accx = 0;
    accy = 0;
    image.load(":/ExtraCredit.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(22);
    rect.setWidth(22);
    letter = 0.05;
    caught = false;
    resetState();
}

ExtraCredit::~ExtraCredit(){
    std::cout << ("Extra Credit deleted\n");
}

void ExtraCredit::autoMove(){
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

void ExtraCredit::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void ExtraCredit::setLetter(int let){
    letter = let;
}

double ExtraCredit::getLetter(){
    return letter;
}

void ExtraCredit::moveDown(int down){
    rect.moveBottom(down);
}

void ExtraCredit::moveLeft(int left){
    rect.moveLeft(left);
}

void ExtraCredit::moveRight(int right){
    rect.moveRight(right);
}

void ExtraCredit::moveUp(int up){
    rect.moveTop(up);
}

void ExtraCredit::setXDir(int x){
    xdir = x;
}

void ExtraCredit::setYDir(int y){
    ydir = y;
}

int ExtraCredit::getXDir(){
    return xdir;
}

int ExtraCredit::getYDir(){
    return ydir;
}

QRect ExtraCredit::getRect(){
    return rect;
}

void ExtraCredit::setRect(QRect rct){
    rect = rct;
}

QImage & ExtraCredit::getImage(){
    return image;
}

bool ExtraCredit::isCaught(){
    return caught;
}

void ExtraCredit::setCaught(bool cght){
    caught = cght;
}


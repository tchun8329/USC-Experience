#include "LetterB.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

LetterB::LetterB(int x, int y) : Grades(x,y){
    //use the x and y for the types of letter B
    accx = 0;
    accy = 0;
    image.load(":/LetterB.png");
    xdir = -1;
    ydir = 0;
    rect = image.rect();
    rect.setHeight(32);
    rect.setWidth(32);
    letter = 3.0;
    caught = false;
    resetState();
}

LetterB::~LetterB(){
    std::cout << ("Letter B deleted\n");
}

void LetterB::autoMove(){
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

void LetterB::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 305 + qrand() % 145;
    rect.moveTo(randx,randy);
}

void LetterB::setLetter(int let){
    letter = let;
}

double LetterB::getLetter(){
    return letter;
}

void LetterB::moveDown(int down){
    rect.moveBottom(down);
}

void LetterB::moveLeft(int left){
    rect.moveLeft(left);
}

void LetterB::moveRight(int right){
    rect.moveRight(right);
}

void LetterB::moveUp(int up){
    rect.moveTop(up);
}

void LetterB::setXDir(int x){
    xdir = x;
}

void LetterB::setYDir(int y){
    ydir = y;
}

int LetterB::getXDir(){
    return xdir;
}

int LetterB::getYDir(){
    return ydir;
}

QRect LetterB::getRect(){
    return rect;
}

void LetterB::setRect(QRect rct){
    rect = rct;
}

QImage & LetterB::getImage(){
    return image;
}

bool LetterB::isCaught(){
    return caught;
}

void LetterB::setCaught(bool cght){
    caught = cght;
}

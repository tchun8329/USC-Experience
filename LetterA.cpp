#include "LetterA.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

LetterA::LetterA(int x, int y) : Grades(x,y){
    //use the x and y for the types of Letter A
    accx = 0;
    accy = 0;
    image.load(":/LetterA.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(16);
    rect.setWidth(16);
    letter = 4.0;
    caught = false;
    resetState();
}

LetterA::~LetterA(){
    std::cout << ("Letter A deleted\n");
}

void LetterA::autoMove(){
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

void LetterA::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 305 + qrand() % 145;
    rect.moveTo(randx,randy);
}

void LetterA::setLetter(int let){
    letter = let;
}

double LetterA::getLetter(){
    return letter;
}

void LetterA::moveDown(int down){
    rect.moveBottom(down);
}

void LetterA::moveLeft(int left){
    rect.moveLeft(left);
}

void LetterA::moveRight(int right){
    rect.moveRight(right);
}

void LetterA::moveUp(int up){
    rect.moveTop(up);
}

void LetterA::setXDir(int x){
    xdir = x;
}

void LetterA::setYDir(int y){
    ydir = y;
}

int LetterA::getXDir(){
    return xdir;
}

int LetterA::getYDir(){
    return ydir;
}

QRect LetterA::getRect(){
    return rect;
}

void LetterA::setRect(QRect rct){
    rect = rct;
}

QImage & LetterA::getImage(){
    return image;
}

bool LetterA::isCaught(){
    return caught;
}

void LetterA::setCaught(bool cght){
    caught = cght;
}

#include "LetterC.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

LetterC::LetterC(int x, int y) : Grades(x,y){
    //use the x and y for the types of Letter C
    accx = 0;
    accy = 0;
    image.load(":/LetterC.png");
    xdir = 0;
    ydir = -1;
    rect = image.rect();
    rect.setHeight(48);
    rect.setWidth(48);
    letter = 2.0;
    caught = false;
    resetState();
}

LetterC::~LetterC(){
    std::cout << ("Letter C deleted\n");
}

void LetterC::autoMove(){
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

void LetterC::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void LetterC::setLetter(int let){
    letter = let;
}

double LetterC::getLetter(){
    return letter;
}

void LetterC::moveDown(int down){
    rect.moveBottom(down);
}

void LetterC::moveLeft(int left){
    rect.moveLeft(left);
}

void LetterC::moveRight(int right){
    rect.moveRight(right);
}

void LetterC::moveUp(int up){
    rect.moveTop(up);
}

void LetterC::setXDir(int x){
    xdir = x;
}

void LetterC::setYDir(int y){
    ydir = y;
}

int LetterC::getXDir(){
    return xdir;
}

int LetterC::getYDir(){
    return ydir;
}

QRect LetterC::getRect(){
    return rect;
}

void LetterC::setRect(QRect rct){
    rect = rct;
}

QImage & LetterC::getImage(){
    return image;
}

bool LetterC::isCaught(){
    return caught;
}

void LetterC::setCaught(bool cght){
    caught = cght;
}


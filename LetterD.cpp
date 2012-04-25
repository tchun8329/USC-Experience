#include "LetterD.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

LetterD::LetterD(int x, int y) : Grades(x,y){
    //use the x and y for the types of Letter D
    accx = 0;
    accy = 0;
    image.load(":/LetterD.png");
    xdir = -1;
    ydir = 1;
    rect = image.rect();
    rect.setHeight(32);
    rect.setWidth(32);
    letter = 1.0;
    caught = false;
    resetState();
}

LetterD::~LetterD(){
    std::cout << ("Letter D deleted\n");
}

void LetterD::autoMove(){
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

void LetterD::resetState(){
    int randx = 315 + qrand() % 245;
    int randy = 345 + qrand() % 105;
    rect.moveTo(randx,randy);
}

void LetterD::setLetter(int let){
    letter = let;
}

double LetterD::getLetter(){
    return letter;
}

void LetterD::moveDown(int down){
    rect.moveBottom(down);
}

void LetterD::moveLeft(int left){
    rect.moveLeft(left);
}

void LetterD::moveRight(int right){
    rect.moveRight(right);
}

void LetterD::moveUp(int up){
    rect.moveTop(up);
}

void LetterD::setXDir(int x){
    xdir = x;
}

void LetterD::setYDir(int y){
    ydir = y;
}

int LetterD::getXDir(){
    return xdir;
}

int LetterD::getYDir(){
    return ydir;
}

QRect LetterD::getRect(){
    return rect;
}

void LetterD::setRect(QRect rct){
    rect = rct;
}

QImage & LetterD::getImage(){
    return image;
}

bool LetterD::isCaught(){
    return caught;
}

void LetterD::setCaught(bool cght){
    caught = cght;
}


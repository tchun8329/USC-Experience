#include "GravityBar.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

GravityBar::GravityBar(int x, int y) : Specials(x,y){
    //use the x and y for the types of GravityBar
    accx = 0;
    accy = 0;
    image.load(":/GravityBar.png");
    xdir = 0;
    ydir = 0;
    rect.setHeight(30);
    rect.setWidth(400);
    letter = 4.0;
    caught = false;
    resetState();
}

GravityBar::~GravityBar(){
    std::cout << ("GravityBar deleted\n");
}

void GravityBar::autoMove(){
    rect.translate(0,0);
}

void GravityBar::resetState(){
    int randx = 315;
    int randy = 345;
    rect.moveTo(randx,randy);
}

void GravityBar::setLetter(int let){
    letter = let;
}

double GravityBar::getLetter(){
    return letter;
}

void GravityBar::moveDown(int down){
    rect.moveBottom(down);
}

void GravityBar::moveLeft(int left){
    rect.moveLeft(left);
}

void GravityBar::moveRight(int right){
    rect.moveRight(right);
}

void GravityBar::moveUp(int up){
    rect.moveTop(up);
}

void GravityBar::setXDir(int x){
    xdir = x;
}

void GravityBar::setYDir(int y){
    ydir = y;
}

int GravityBar::getXDir(){
    return xdir;
}

int GravityBar::getYDir(){
    return ydir;
}

QRect GravityBar::getRect(){
    return rect;
}

void GravityBar::setRect(QRect rct){
    rect = rct;
}

QImage & GravityBar::getImage(){
    return image;
}

bool GravityBar::isCaught(){
    return caught;
}

void GravityBar::setCaught(bool cght){
    caught = cght;
}

#include "USC_Student.h"
#include <iostream>

USC_Student::USC_Student(){

    image.load(":/Lossless-circle.png");
    rect = image.rect();
    rect.setWidth(16);
    rect.setHeight(16);
    resetState();
}

USC_Student::~USC_Student(){
    std::cout << ("Student deleted\n");
}

void USC_Student::moveLeft(int left){
    if(rect.left() > 215){
        //this is the leftmost the student can go
        rect.moveTo(left, rect.top());
    }
}

void USC_Student::moveRight(int right){
    if(rect.right() < 660){
        //this is the rightmost the student can go
        rect.moveTo(right,rect.top());
    }
}

void USC_Student::moveDown(int down){
    if(rect.bottom() < 572){
        //this is the bottommost the student can go
        rect.moveTo(rect.left(),down);
    }
}

void USC_Student::moveUp(int up){
    if(rect.top() > 218){
        //this is the highest the student can go
        rect.moveTo(rect.left(),up);
    }
}

void USC_Student::resetState(){
    rect.moveTo(216,219);
}

QRect USC_Student::getRect(){
    return rect;
}

QImage & USC_Student::getImage(){
    return image;
}

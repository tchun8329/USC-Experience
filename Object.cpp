#include "Grades.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Object::Object(int x,int y){
    x = x;
    y = y;
}

Object::~Object(){
    std::cout << ("Object deleted\n");
}

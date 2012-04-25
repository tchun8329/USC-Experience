#include "Grades.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Grades::Grades(int x, int y) : Object(x,y){

}
Grades::~Grades(){
    std::cout << ("Grades deleted\n");
}

#include "Specials.h"
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

Specials::Specials(int x, int y) : Object(x,y){

}
Specials::~Specials(){
    std::cout << ("Specials deleted\n");
}

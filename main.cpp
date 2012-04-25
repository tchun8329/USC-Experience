#include "USC_Experience.h"
#include <QDesktopWidget>
#include <QGridLayout>
#include <QApplication>
#include <QPalette>
#include <QTime>


void center(QWidget &widget){
    int x,y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();
    QPalette p;
    QPixmap pixmap1(":/finalbackground2.png");
    int WIDTH = pixmap1.width();
    int HEIGHT = pixmap1.height();
    QPixmap pixmap(pixmap1.scaled(WIDTH,HEIGHT));
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth - WIDTH)/2;
    y = (screenHeight - HEIGHT)/2;
    widget.setGeometry(x,y,WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
    //this setFixedSize needs to change for the side OASIS
    p.setBrush(QPalette::Background, pixmap);;
    widget.setPalette(p);
}

int main(int argc, char *argv[]){

    QApplication app(argc,argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    USC_Experience experience;
    //experience.setWindowTitle("USC EXPERIENCE");
    experience.show();
    center(experience);
    return app.exec();

}

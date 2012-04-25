#ifndef USC_STUDENT_H
#define USC_STUDENT_H

#include <QImage>
#include <QRect>

class USC_Student{

public:
    USC_Student();
    ~USC_Student();

public:
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);
    QRect getRect();
    QImage & getImage();

private:
    QImage image;
    QRect rect;
};

#endif // USC_STUDENT_H

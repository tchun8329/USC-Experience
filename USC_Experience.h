#ifndef USC_EXPERIENCE_H
#define USC_EXPERIENCE_H

#include "USC_Student.h"
#include "LetterA.h"
#include "LetterB.h"
#include "LetterC.h"
#include "LetterD.h"
#include "LetterF.h"
#include "Cheat.h"
#include "ExtraCredit.h"
#include "FreshmanForgiveness.h"
#include "Hangover.h"
#include "OfficeHours.h"
#include "Sleep.h"
#include "Study.h"
#include <QWidget>
#include <QKeyEvent>

class USC_Experience : public QWidget{
    Q_OBJECT
public:
    USC_Experience(QWidget *parent = 0);
    ~USC_Experience();
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void createNewLetter(double);
    void victory();
    void checkOverlap();
    void freeze();
    void speedUp();
    void slowDown();
    void gamble();
private:
    int posx;
    int posy;
    int timerId;
    int A_caught;
    int B_caught;
    int C_caught;
    int D_caught;
    int F_caught;
    int special;
    int specials_caught;
    int Number_fails_left;
    int EXCR;
    int OFHR;
    int HGOR;
    int CHET;
    int FRFS;
    int STDY;
    int SLEP;
    int slowGameDown;
    double GPA;
    LetterA *A_alpha[30];
    LetterB *B_beta[30];
    LetterC *C_gamma[30];
    LetterD *D_delta[30];
    LetterF *F_epsilon[30];
    USC_Student *student;
    FreshmanForgiveness *FF[5];
    ExtraCredit *EC[5];
    OfficeHours *OH[2];
    Hangover *HO[5];
    Cheat *CT[5];
    Study *SY[5];
    Sleep *SP[5];
    bool newLettermade;
    bool specialFlag;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool frozen;
    bool speed;
    bool cheated;
    bool sleeping;
    bool COMM;
    bool CSCI;
    bool PHYSENG;
};

#endif // USC_EXPERIENCE_H

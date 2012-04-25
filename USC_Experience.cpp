#include "USC_Experience.h"
#include <QPainter>
#include <QApplication>
#include <QRect>
#include <QImage>
#include "stdlib.h"

USC_Experience::USC_Experience(QWidget *parent):QWidget(parent){
    posx = 0;
    posy = 0;
    GPA = 0.0;
    A_caught = 0;
    B_caught = 0;
    C_caught = 0;
    D_caught = 0;
    F_caught = 0;
    special = -1;
    specials_caught = 0;
    Number_fails_left = 0;
    EXCR = 0,
    OFHR = 0,
    HGOR = 0,
    CHET = 0,
    FRFS = 0,
    STDY = 0,
    SLEP = 0;
    slowGameDown = 10;
    gameOver = false;
    gameWon = false;
    paused = false;
    newLettermade = false;
    gameStarted = false;
    specialFlag = false;
    frozen = false;
    speed = false;
    cheated = false;
    sleeping = false;
    COMM = false;
    CSCI = true;
    PHYSENG = false;
    student = new USC_Student();
    for (int i = 0; i < 12; i++){
        for (int j = 0 ; j < 30 ; j++){
            if(i == 0)
                A_alpha[j] = new LetterA(0,0);
            else if (i == 1)
                B_beta[j] = new LetterB(0,0);
            else if (i == 2)
                C_gamma[j] = new LetterC(0,0);
            else if (i == 3)
                D_delta[j] = new LetterD(0,0);
            else if (i == 4)
                F_epsilon[j] = new LetterF(0,0);
            else if (i == 5 && j < 5)
                EC[j] = new ExtraCredit(0,0);
            else if (i == 6 && j < 5)
                HO[j] = new Hangover(0,0);
            else if (i == 7 && j < 5)
                CT[j] = new Cheat(0,0);
            else if (i == 8 && j < 5)
                FF[j] = new FreshmanForgiveness(0,0);
            else if (i == 9 && j < 5)
                SP[j] = new Sleep(0,0);
            else if (i == 10 && j < 5)
                SY[j] = new Study(0,0);
            else if (i == 11 && j < 2)
                OH[j] = new OfficeHours(0,0);

        }
    }
}

USC_Experience::~USC_Experience(){
    delete student;
    for (int i = 0; i < 12; i++){
        for (int j = 0 ; j < 30 ; j++){
            if(i == 0)
                delete A_alpha[j];
            else if (i == 1)
                delete B_beta[j];
            else if (i == 2)
                delete C_gamma[j];
            else if (i == 3)
                delete D_delta[j];
            else if (i == 4)
                delete F_epsilon[j];
            else if (i == 5 && j < 5)
                delete EC[j];
            else if (i == 6 && j < 5)
                delete SP[j];
            else if (i == 7 && j < 5)
                delete CT[j];
            else if (i == 8 && j < 5)
                delete FF[j];
            else if (i == 9 && j < 5)
                delete HO[j];
            else if (i == 10 && j < 5)
                delete SY[j];
            else if (i == 11 && j < 2)
                delete OH[j];
        }
    }
}

void USC_Experience::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QFont font("Courier New",10,QFont::Normal);
    QString s;
    int total = (A_caught+B_caught+C_caught+D_caught+F_caught);
    s.sprintf("GPA: %.2f \nTotal Grades: %d\nAs: %d\nBs: %d\nCs: %d\nDs: %d\nLives Lost: %d\nIf you catch 5 F's, you lose.",
              GPA/total,total,A_caught,B_caught,C_caught,D_caught,F_caught,Number_fails_left);
    painter.setFont(font);
    painter.drawText(710,120,1000,400,true,s);
    if(gameOver){
        QFont font("Times",18,QFont::Bold);
        QFontMetrics fm(font);
        int h = height();
        int w = width();
        painter.setFont(font);
        painter.translate(QPoint(w/2,h/2));
        if(cheated){
            int textWidth = fm.width("Game Over. You Cheated!");
            painter.drawText(-textWidth/2,0,"Game Over. You Cheated!");
        }
        else{
            int textWidth = fm.width("Game Over");
            painter.drawText(-textWidth/2,0,"Game Over");
        }
    }
    else if(gameWon){
        QFont font("Times",18,QFont::Bold);
        QFontMetrics fm(font);
        painter.setFont(font);
        student->resetState();
        painter.drawImage(student->getRect(),student->getImage());
        int h = height();
        int w = width();
        painter.translate(QPoint(w/3,h/2));
        if(GPA/total < 2.00){
            int textWidth = fm.width("Oh No!\nYou are a USC Dropout!");
            painter.drawText(-textWidth/2,0,"Oh No!\nYou are a USC Dropout!");
        }
        else if(GPA/total >= 2.00 && COMM && PHYSENG){
            int textWidth = fm.width("Congratulations!\nYou are a USC Graduate!");
            painter.drawText(-textWidth/2,0,"Congratulations!\nYou are a USC Graduate!\nPlay Again?");
            COMM = false;
            PHYSENG = false;
        }
        else if(GPA/total >= 2.00 && !COMM){
            COMM = true;
            int textWidth = fm.width("Drag the SC for Level 2!");
            painter.drawText(-textWidth/2,0,"Drag the SC for Level 2!");
        }
        else if(GPA/total >= 2.00 && COMM && !PHYSENG){
            PHYSENG = true;
            int textWidth = fm.width("Drag the SC for Final Level!");
            painter.drawText(-textWidth/2,0,"Drag the SC for Final Level!");
        }

    }
    else{
        if(!gameStarted){
            painter.drawText(220,300,1500,300,true,"Drag the SC Logo with your cursor to begin");
            painter.drawImage(student->getRect(),student->getImage());
        }
        else{
            for (int i = 0; i < 1+A_caught ; i++)
                if(!A_alpha[i]->isCaught()){
                    painter.drawImage(A_alpha[i]->getRect(),A_alpha[i]->getImage());
                }
            for (int j = 0; j < 3+B_caught ; j++)
                if(!B_beta[j]->isCaught()){
                    painter.drawImage(B_beta[j]->getRect(),B_beta[j]->getImage());
                }
            for (int k = 0; k < 4+C_caught ; k++)
                if(!C_gamma[k]->isCaught()){
                    painter.drawImage(C_gamma[k]->getRect(),C_gamma[k]->getImage());
                }
            for (int x = 0; x < 3+D_caught ; x++)
                if(!D_delta[x]->isCaught()){
                    painter.drawImage(D_delta[x]->getRect(),D_delta[x]->getImage());
                }
            if(COMM && !PHYSENG)
                for (int y = 0; y < 1+F_caught ; y++)
                    if(!F_epsilon[y]->isCaught()){
                        painter.drawImage(F_epsilon[y]->getRect(),F_epsilon[y]->getImage());
                    }
            if(COMM && PHYSENG)
                for (int y = 0; y < 3+F_caught ; y++)
                    if(!F_epsilon[y]->isCaught()){
                        painter.drawImage(F_epsilon[y]->getRect(),F_epsilon[y]->getImage());
                    }
            for(int z = 0 ; z < EXCR ; z++){
                if(special == 0 && !EC[z]->isCaught() && EXCR < 5){
                    painter.drawImage(EC[z]->getRect(),EC[z]->getImage());
                }
            }
            for(int a = 0 ; a < CHET ; a++){
                if (special == 1 && !CT[a]->isCaught() && CHET < 5){
                    painter.drawImage(CT[a]->getRect(),CT[a]->getImage());
                }
            }
            for(int b = 0 ; b < FRFS ; b++){
                if (special == 2 && !FF[b]->isCaught() && FRFS < 5){
                    painter.drawImage(FF[b]->getRect(),FF[b]->getImage());
                }
            }
            for(int c = 0 ; c < HGOR ; c++){
                if (special == 3 && !HO[c]->isCaught() && HGOR < 5){
                    painter.drawImage(HO[c]->getRect(),HO[c]->getImage());
                }
            }
            for(int d = 0 ; d < STDY ; d++){
                if (special == 4 && !SY[d]->isCaught() && STDY < 5){
                    painter.drawImage(SY[d]->getRect(),SY[d]->getImage());
                }
            }
            for(int e = 0 ; e < SLEP ; e++){
                if (special == 5 && !SP[e]->isCaught() && SLEP < 5){
                    painter.drawImage(SP[e]->getRect(),SP[e]->getImage());
                }
            }
            for(int f = 0 ; f < OFHR ; f++){
                if (special == 6 && !OH[f]->isCaught() && OFHR < 2){
                    painter.drawImage(OH[f]->getRect(),OH[f]->getImage());
                }
            }
        }
        painter.drawImage(student->getRect(),student->getImage());
    }
}

void USC_Experience::timerEvent(QTimerEvent *){
    if (!frozen){
        for (int i = 0; i < 1+A_caught ; i++)
            if(!A_alpha[i]->isCaught()){
                A_alpha[i]->autoMove();
            }
        for (int j = 0; j < 3+B_caught ; j++)
            if(!B_beta[j]->isCaught()){
                B_beta[j]->autoMove();
            }
        for (int k = 0; k < 4+C_caught ; k++)
            if(!C_gamma[k]->isCaught()){
                C_gamma[k]->autoMove();
            }
        for (int x = 0; x < 3+D_caught ; x++)
            if(!D_delta[x]->isCaught()){
                D_delta[x]->autoMove();;
            }
        if(COMM && !PHYSENG){
            for (int y = 0; y < 1+F_caught ; y++)
                if(!F_epsilon[y]->isCaught()){
                    F_epsilon[y]->autoMove();
                }
        }
        if(COMM && PHYSENG){
            for (int y = 0; y < 3+F_caught ; y++)
                if(!F_epsilon[y]->isCaught()){
                    F_epsilon[y]->autoMove();
                }
        }
        for(int z = 0 ; z < EXCR ; z++){
            if(special == 0 && !EC[z]->isCaught() && EXCR < 5){
                EC[z]->autoMove();
            }
        }
        for(int a = 0 ; a < CHET ; a++){
            if (special == 1 && !CT[a]->isCaught() && CHET < 5){
                CT[a]->autoMove();
            }
        }
        for(int b = 0 ; b < FRFS ; b++){
            if (special == 2 && !FF[b]->isCaught() && FRFS < 5){
                FF[b]->autoMove();;
            }
        }
        for(int c = 0 ; c < HGOR ; c++){
            if (special == 3 && !HO[c]->isCaught() && HGOR < 5){
                HO[c]->autoMove();
            }
        }
        for(int d = 0 ; d < STDY ; d++){
            if (special == 4 && !SY[d]->isCaught() && STDY < 5){
                SY[d]->autoMove();
            }
        }
        for(int e = 0 ; e < SLEP ; e++){
            if (special == 5 && !SP[e]->isCaught() && SLEP < 5){
                SP[e]->autoMove();
            }
        }
        for(int f = 0 ; f < OFHR ; f++){
            if (special == 6 && !OH[f]->isCaught() && OFHR < 2){
                OH[f]->autoMove();
            }
        }
    }
    checkOverlap();
    repaint();
}

void USC_Experience::mouseMoveEvent(QMouseEvent *event){
    this->setMouseTracking(true);
    this->setCursor(Qt::OpenHandCursor);
    if(gameStarted &&
            event->pos().x() >= 215 &&
            event->pos().x() <= 660 &&
            event->pos().y() >= 218 &&
            event->pos().y() <= 572){
        this->setCursor(Qt::BlankCursor);
        if(COMM && !PHYSENG)
            for (int i = 0 ; i < 1+F_caught ; i++){
                F_epsilon[i]->setXAcc(event->pos().x());
                F_epsilon[i]->setYAcc(event->pos().y());
                update();
            }
        else if(COMM && PHYSENG){
            for (int i = 0 ; i < 3+F_caught ; i++){
                F_epsilon[i]->setXAcc(event->pos().x());
                F_epsilon[i]->setYAcc(event->pos().y());
                update();
            }
        }
    }
    else
        this->setCursor(Qt::OpenHandCursor);
    if(event->buttons() == Qt::LeftButton){
        startGame();
    }
    int x = student->getRect().x();
    int y = student->getRect().y();
    if (event->pos().x() > x && x <= 660){
        while(event->pos().x() != x)
            student->moveRight(++x);
    }
    if (event->pos().x() < x && x >= 215){
        while(event->pos().x() != x)
            student->moveLeft(--x);
    }
    if (event->pos().y() > y){
        while(event->pos().y() != y && y >= 218)
            student->moveDown(++y);
    }
    if (event->pos().y() < y){
        while(event->pos().y() != y && y <= 572)
            student->moveUp(--y);
    }
}

void USC_Experience::keyPressEvent(QKeyEvent *event){
        switch(event->key()){
        case Qt::Key_P:
            {
              pauseGame();
            }
            break;
        case Qt::Key_Escape:
            {
              qApp->exit();
            }
            break;
        default:
            QWidget::keyPressEvent(event);
        }
}

void USC_Experience::startGame(){
    if(!gameStarted){
        student->resetState();
        for (int i = 0; i < 1+A_caught ; i++){
            A_alpha[i]->setCaught(false);
            A_alpha[i]->resetState();
        }
        for (int j = 0; j < 3+B_caught ; j++){
            B_beta[j]->setCaught(false);
            B_beta[j]->resetState();
        }
        for (int k = 0; k < 4+C_caught ; k++){
            C_gamma[k]->setCaught(false);
            C_gamma[k]->resetState();
        }
        for (int x = 0; x < 3+D_caught ; x++){
            D_delta[x]->setCaught(false);
            D_delta[x]->resetState();
        }
        for (int y = 0; y < 1+F_caught ; y++){
            F_epsilon[y]->setCaught(false);
            F_epsilon[y]->resetState();
        }
        for (int z = 0; z < 5 ; z++){
            EC[z]->setCaught(false);
            EC[z]->resetState();
            HO[z]->setCaught(false);
            HO[z]->resetState();
            CT[z]->setCaught(false);
            CT[z]->resetState();
            FF[z]->setCaught(false);
            FF[z]->resetState();
            SY[z]->setCaught(false);
            SY[z]->resetState();
            SP[z]->setCaught(false);
            SP[z]->resetState();
            if (z < 2){
                OH[z]->setCaught(false);
                OH[z]->resetState();
            }
        }
        A_caught = 0;
        B_caught = 0;
        C_caught = 0;
        D_caught = 0;
        F_caught = 0;
        specialFlag = false;
        gameOver = false;
        gameWon = false;
        gameStarted = true;
        frozen = false;
        speed = false;
        cheated = false;
        sleeping = false;
        special = -1;
        specials_caught = 0;
        EXCR = 0,
        OFHR = 0,
        HGOR = 0,
        CHET = 0,
        FRFS = 0,
        STDY = 0,
        SLEP = 0;
        timerId = startTimer(10);
    }
}

void USC_Experience::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  }
  else {
    paused = TRUE;
    killTimer(timerId);
  }
}

void USC_Experience::stopGame()
{
  killTimer(timerId);
  gameOver = TRUE;
  gameStarted = FALSE;
}

void USC_Experience::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  gameStarted = FALSE;
}

void USC_Experience::checkOverlap()
{
    GPA = 0;
    //specials_caught = 0;
    Number_fails_left = 0;
    int k = -1;
    bool    A_flag = false,
            B_flag = false,
            C_flag = false,
            D_flag = false,
            F_flag = false,
            EXCR_flag = false,
            OFHR_flag = false,
            HGOR_flag = false,
            CHET_flag = false,
            FRFS_flag = false,
            STDY_flag = false,
            SLEP_flag = false;
    int Number_caught = (A_caught+B_caught+C_caught+D_caught+F_caught);
    for (int i=0, j=0, l=0; i<12+Number_caught; i++) {
        if (j==30)
            victory();
        if (l==5)
            stopGame();
        if (i == 11+Number_caught)
            Number_fails_left = l;
        if(i < (1+A_caught)){
            if(A_alpha[i]->isCaught()){
                j++;
                GPA += A_alpha[i]->getLetter();
            }
            else if(!A_alpha[i]->isCaught() && A_alpha[i]->getRect().intersects(student->getRect())){
                A_alpha[i]->setCaught(true);
                k = i;
                A_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }
        if(i < (3+B_caught)){
            if(B_beta[i]->isCaught()){
                j++;
                GPA += B_beta[i]->getLetter();
            }
            else if (!B_beta[i]->isCaught() && B_beta[i]->getRect().intersects(student->getRect())){
                B_beta[i]->setCaught(true);
                k = i;
                B_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }

        if(i < (4+C_caught)){
            if(C_gamma[i]->isCaught()){
                j++;
                GPA += C_gamma[i]->getLetter();
            }
            else if (!C_gamma[i]->isCaught() && C_gamma[i]->getRect().intersects(student->getRect())){
                C_gamma[i]->setCaught(true);
                k = i;
                C_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }

        if(i < (3+D_caught)){
            if(D_delta[i]->isCaught()){
                j++;
                GPA += D_delta[i]->getLetter();
            }
            else if (!D_delta[i]->isCaught() && D_delta[i]->getRect().intersects(student->getRect())){
                D_delta[i]->setCaught(true);
                k = i;
                D_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }

        if(i < (1+F_caught) && COMM){
            if(F_epsilon[i]->isCaught()){
                l++;
                j++;
                GPA += F_epsilon[i]->getLetter();
            }
            else if(!F_epsilon[i]->isCaught() && F_epsilon[i]->getRect().intersects(student->getRect())){
                F_epsilon[i]->setCaught(true);
                k = i;
                F_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }
        if(i < (3+F_caught) && COMM && PHYSENG){
            if(F_epsilon[i]->isCaught()){
                l++;
                j++;
                GPA += F_epsilon[i]->getLetter();
            }
            else if(!F_epsilon[i]->isCaught() && F_epsilon[i]->getRect().intersects(student->getRect())){
                F_epsilon[i]->setCaught(true);
                k = i;
                F_flag = true;
                if (frozen){
                    frozen = false;
                    freeze();
                }
                if(speed){
                    speed = false;
                    speedUp();
                }
                if (sleeping){
                    sleeping = false;
                    slowDown();
                }
            }
        }
        //if (i < 1+EXCR+OFHR+HGOR+CHET+FRFS+STDY+SLEP){
        if (i < EXCR){
            if(EC[i]->isCaught()){
                GPA += EC[i]->getLetter();
            }
            if(!EC[i]->isCaught() && EC[i]->getRect().intersects(student->getRect())){
                EC[i]->setCaught(true);
                specialFlag = false;
                EXCR_flag = true;
                special = -1;
                k = i;
            }
        }
        if (i < OFHR){
            if(!OH[i]->isCaught() && OH[i]->getRect().intersects(student->getRect())){
                OH[i]->setCaught(true);
                specialFlag = false;
                OFHR_flag = true;
                special = -1;
                k = i;
                frozen = true;
            }
        }
        if (i < HGOR){
            if(!HO[i]->isCaught() && HO[i]->getRect().intersects(student->getRect())){
                HO[i]->setCaught(true);
                specialFlag = false;
                HGOR_flag = true;
                special = -1;
                k = i;
                speed = true;
            }
        }
        if (i < CHET){
            if(CHET < 5 && special ==1){
                if(!CT[i]->isCaught() && CT[i]->getRect().intersects(student->getRect())){
                    CT[i]->setCaught(true);
                    specialFlag = false;
                    CHET_flag = true;
                    special = -1;
                    k = i;
                }
            }
        }
        if (i < FRFS){
            if(FF[i]->isCaught()){
                l++;
                for(int q = 30 ; q > 0 ; q--)
                    if(F_epsilon[q]->isCaught()){
                        F_epsilon[q]->setCaught(false);
                        F_caught--;
                        break;
                    }
            }
            if(!FF[i]->isCaught() && FF[i]->getRect().intersects(student->getRect())){
                FF[i]->setCaught(true);
                specialFlag = false;
                FRFS_flag = true;
                special = -1;
                k = i;
            }
        }
        if (i < STDY){
            if(!SY[i]->isCaught() && SY[i]->getRect().intersects(student->getRect())){
                SY[i]->setCaught(true);
                specialFlag = false;
                STDY_flag = true;
                special = -1;
                k = i;
            }
        }
        if(i < SLEP){
            if(!SP[i]->isCaught() && SP[i]->getRect().intersects(student->getRect())){
                SP[i]->setCaught(true);
                specialFlag = false;
                SLEP_flag = true;
                special = -1;
                k = i;
                sleeping = true;
            }
        }
        if(     A_flag || B_flag || C_flag || D_flag || F_flag ||
                EXCR_flag || OFHR_flag || HGOR_flag || CHET_flag ||
                FRFS_flag || STDY_flag || SLEP_flag){
            newLettermade = true;
            if(A_flag)
                createNewLetter(A_alpha[k]->getLetter());
            else if(B_flag)
                createNewLetter(B_beta[k]->getLetter());
            else if(C_flag)
                createNewLetter(C_gamma[k]->getLetter());
            else if(D_flag)
                createNewLetter(D_delta[k]->getLetter());
            else if (F_flag)
                createNewLetter(F_epsilon[k]->getLetter());
            else if (EXCR_flag)
                createNewLetter(EC[k]->getLetter());
            else if (OFHR_flag){
                freeze();
                //createNewLetter(EC[k]->getLetter());
            }
            else if (HGOR_flag){
                speedUp();
                //createNewLetter(EC[k]->getLetter());
            }
            else if(CHET_flag){
                gamble();
                //createNewLetter(EC[k]->getLetter());
            }
            else if (STDY_flag){
                A_caught++;
                STDY_flag = false;
            }
            else if (SLEP_flag){
                slowDown();
            }
            break;
        }
    }
    if (!specialFlag){
        int random_Num = qrand() % 7;
        specialFlag = true;
        if (random_Num == 0 && EXCR < 5){
            special = 0;
            EXCR++;
        }
        else if (random_Num == 1 && OFHR < 2){
            special = 6;
            OFHR++;
        }
        else if (random_Num == 2 && HGOR < 5){
            special = 3;
            HGOR++;
        }
        else if (random_Num == 3 && CHET < 5){
            special = 1;
            CHET++;
        }
        else if (random_Num == 4 && FRFS < 5){
            special = 2;
            FRFS++;
        }
        else if (random_Num == 5 && STDY < 5){
            special = 4;
            STDY++;
        }
        else if (random_Num == 6 && SLEP < 5){
            special = 5;
            SLEP++;
        }
        else{
            special = -1;
            specialFlag = false;
        }
    }
}

void USC_Experience::gamble(){
    int gamble_Num = qrand() % 100;
    bool gain = false;
    if (gamble_Num > 50)
        while(!gain){
            for(int i = 0 ; i < 30 ; i++)
                if(!A_alpha[i]->isCaught()){
                    A_alpha[i]->setCaught(true);
                    gain = true;
                    A_caught++;
                    break;
                }
        }
    else{
        cheated = true;
        stopGame();
    }
}

void USC_Experience::slowDown(){
    for (int j = 0; j < 3+B_caught ; j++){
        if(!B_beta[j]->isCaught() && speed){
            B_beta[j]->setXDir(B_beta[j]->getXDir()/2);
        }
        else{
            B_beta[j]->setXDir(-1);
        }
    }
    for (int k = 0; k < 4+C_caught ; k++){
        if(!C_gamma[k]->isCaught() && speed){
            C_gamma[k]->setYDir(2*C_gamma[k]->getYDir()/2);
        }
        else{
            C_gamma[k]->setYDir(-1);
        }
    }
    for (int x = 0; x < 3+D_caught ; x++){
        if(!D_delta[x]->isCaught() && speed){
            D_delta[x]->setXDir(2*D_delta[x]->getXDir()/2);
            D_delta[x]->setYDir(2*D_delta[x]->getYDir()/2);
        }
        else{
            D_delta[x]->setXDir(-1);
            D_delta[x]->setYDir(1);
        }
    }
}

void USC_Experience::speedUp(){
    for (int j = 0; j < 3+B_caught ; j++){
        if(!B_beta[j]->isCaught() && speed){
            B_beta[j]->setXDir(2*B_beta[j]->getXDir());
        }
        else{
            B_beta[j]->setXDir(-1);
        }
    }
    for (int k = 0; k < 4+C_caught ; k++){
        if(!C_gamma[k]->isCaught() && speed){
            C_gamma[k]->setYDir(2*C_gamma[k]->getYDir());
        }
        else{
            C_gamma[k]->setYDir(-1);
        }
    }
    for (int x = 0; x < 3+D_caught ; x++){
        if(!D_delta[x]->isCaught() && speed){
            D_delta[x]->setXDir(2*D_delta[x]->getXDir());
            D_delta[x]->setYDir(2*D_delta[x]->getYDir());
        }
        else{
            D_delta[x]->setXDir(-1);
            D_delta[x]->setYDir(1);
        }
    }
}

void USC_Experience::freeze(){
    for (int j = 0; j < 3+B_caught ; j++){
        if(!B_beta[j]->isCaught() && frozen){
            B_beta[j]->setXDir(0);
            B_beta[j]->setYDir(0);
        }
        else{
            B_beta[j]->setXDir(-1);
        }
    }
    for (int k = 0; k < 4+C_caught ; k++){
        if(!C_gamma[k]->isCaught() && frozen){
            C_gamma[k]->setXDir(0);
            C_gamma[k]->setYDir(0);
        }
        else{
            C_gamma[k]->setYDir(-1);
        }
    }
    for (int x = 0; x < 3+D_caught ; x++){
        if(!D_delta[x]->isCaught() && frozen){
            D_delta[x]->setXDir(0);
            D_delta[x]->setYDir(0);
        }
        else{
            D_delta[x]->setXDir(-1);
            D_delta[x]->setYDir(1);
        }
    }
    if(COMM)
        for (int y = 0; y < 1+F_caught ; y++)
            if(!F_epsilon[y]->isCaught() && frozen){
                F_epsilon[y]->setXDir(0);
                F_epsilon[y]->setYDir(0);
            }
}

void USC_Experience::createNewLetter(double iteration){

    if(iteration == 4.0)
        A_caught++;
    else if (iteration == 3.0)
        B_caught++;
    else if (iteration == 2.0)
        C_caught++;
    else if (iteration == 1.0)
        D_caught++;
    else if (iteration == 0.0)
        F_caught++;
    else
        specials_caught++;
    newLettermade = false;
}

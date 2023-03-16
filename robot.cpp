//
// Created by Hiep Le on 24.02.23.
//
#include <iostream>
#include "robot.h"
#include "felder.h"
#include <time.h>
using namespace std;


Robot::Robot() {
    pos = {.x = 0, .y = 0};
    numLives = 3;
    numPoints = 0;
}

int Robot::getNumLives() {
    return numLives;
}

int Robot::getNumPoints() {
    return numPoints;
}

void Robot::printMap(int array[5][5], int yPosition, int xPosition) {

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == yPosition && j == xPosition){
                array[i][j] = '@';
            }
            //to set the previous position to leer
            if(array[i][j] == '@'){
                if(i != yPosition || j != xPosition ){
                    array[i][j] = leer;
                }
            }
            if(i == yPosition && j == xPosition){
                printf("🤖 |");
            }
            else if(array[i][j] == leer){
                printf("☘️ |");
            }
            else if(array[i][j] == gefahren){
                printf("❗️ |");
            }else if(array[i][j] == brunnen){
                printf("🧚 |");
            }else if(array[i][j] == relikt){
                printf("👑 |");
            }
        }
        printf("\n");
    }
}
void Robot::printStat(int live, int point) {
    cout << "\nYour live: " << live <<endl;
    cout << "\nYour point: " << point <<endl;
}
// function for small game
int Robot::getGameForGefahren() {
    srand(time(0));
    int zufall = rand() % 2;
    int number;
    cin >> number;
    if(number == zufall){
        return 1;
    } return 0;
}

int Robot::getGameforBrunnen() {
    srand(time(0));
    int zufall = rand() % 3;
    char answer;
    cin >> answer;
    // rock is 1, paper is 2, scissor is 3
    // rock : r, paper: p, scissor: s
    switch (answer) {
        case 'r':
            if(zufall == 1){
                return 1;
            }else if(zufall == 3){
                return 1;
            }else{
                return 0;
            }

        case 'p':
            if(zufall == 1){
                return 1;
            }else if(zufall == 2){
                return 1;
            }else{
                return 0;
            }

        case 's':
            if(zufall == 2){
                return 1;
            }else if(zufall == 3){
                return 1;
            }else{
                return 0;
            }
    }
}
int Robot::getGameForRelikt() {
    srand(time(0));
    int zufall = rand() % 2;
    int answer;
    cin >> answer;
    if(answer == zufall){
        return 1;
    }else{
        return 0;
    }
}


void Robot::countPointAndLife(int array[5][5], int yPosition, int xPosition, Robot *Robot) {
        if(array[yPosition][xPosition] == gefahren){
            cout << "\nLet's play a dead game" << endl;
        cout << "\nIt is Head or Tail" << endl;
        cout << "\n1 is Head and 2 is Tail: " << endl;
        cout << "\nIf your answer is wrong, I will shot you!!" << endl;

            if(!Robot->getGameForGefahren()){
                cout << "\nYou lost one life" << endl;
                Robot->numLives--;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }else{
                cout << "\nYou are lucky this time" << endl;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }

        }else if(array[Robot->pos.y][Robot->pos.x] == brunnen){
            cout << "\nLet's play Rock, Paper, Scissor (Rock:r, Paper:p, Scissor: s)" << endl;
            cout << "\nYou won't get point if you lose: " << endl;
            if(!Robot->getGameforBrunnen()){
                cout << "\nYou don't get any thing" << endl;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }else {
                cout << "\nYou are lucky this time" << endl;
                Robot->numLives++;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }

        }
        else if(array[Robot->pos.y][Robot->pos.x] == relikt){
            cout << "\nYou have a chance to win 2 point" << endl;
            cout << "\n1 is Yes and 2 is No" << endl;
            if(!Robot->getGameForRelikt()){
                cout << "\nOnly one for today" << endl;
                Robot->numPoints++;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }else{
                cout << "\nYou are lucky this time" << endl;
                Robot->numPoints++;
                Robot->numPoints++;
                printStat(Robot->getNumLives(), Robot->getNumPoints());
            }

        }
        printMap(array, Robot->pos.y, Robot->pos.x);
}
void Robot::countGame(int countGame, Robot *Robot) {
    if(countGame > 0){
        Robot->numLives= Robot->numLives - countGame;
        cout << "Now you only have this amount of lives: " << Robot->getNumLives() << endl;
    }
}
int checkOkToMove(int yPosition, int xPosition){
    if(xPosition < 0 || xPosition > 4){
        return 0;
    }else if(yPosition < 0 || yPosition > 4){
        return 0;
    }else{
        return 1;
    }
}
void Robot::playGame(char a, Robot *Robot, int array[5][5]) {

    switch(a){
        case 'w':

            Robot->pos.y--;
            //DummyEnemy.pos.y--;
            if(!checkOkToMove(Robot->pos.y--, Robot->pos.x)){
                cout << "\nInvalid move" << endl;

                Robot->pos.y++;
                //DummyEnemy.pos.x++;
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }else{
                //check lives and points
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }

            break;
        case 's':
            Robot->pos.y++;
            //DummyEnemy.pos.y++;
            if(!checkOkToMove(Robot->pos.y, Robot->pos.x)){
                cout << "\nInvalid move" << endl;
                Robot->pos.y--;
                //DummyEnemy.pos.y--;
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }else{
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }
            break;
        case 'd':
            Robot->pos.x++;
            //DummyEnemy.pos.x++;
            if(!checkOkToMove(Robot->pos.y, Robot->pos.x)){
                cout << "\nInvalid move" << endl;
                Robot->pos.x--;
                //DummyEnemy.pos.x--;
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }else{
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }
            break;
        case 'a':
            Robot->pos.x--;
            //DummyEnemy.pos.x--;
            if(!checkOkToMove(Robot->pos.y, Robot->pos.x)){
                cout << "\nInvalid move" << endl;
                Robot->pos.x++;
                //DummyEnemy.pos.x++;
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }else{
                countPointAndLife(array, Robot->pos.y, Robot->pos.x, &*Robot);
            }
            break;
        default:
            cout << "\nInvalid" << endl;
    }
}

//int Robot::countNumLives(Robot *Robot) {
//    return Robot->getNumPoints();
//}


//int Robot::getXRobot() {
//    return this->pos.x;
//}
//
//int Robot::getYRobot() {
//    return this->pos.y;
//}
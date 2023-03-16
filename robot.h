//
// Created by Hiep Le on 24.02.23.
//

#ifndef OSENCRAWLERMITKLASSEN_ROBOT_H
#define OSENCRAWLERMITKLASSEN_ROBOT_H
#include "position.h"

class Robot {
public:
    Robot();
    position pos;
    //function from the first exercise
    void countPointAndLife(int array[5][5], int yPosition, int xPosition, Robot* Robot);
    void printMap(int array[5][5], int yPosition, int xPosition);
    void printStat(int live, int point);
    void countGame(int countGame, Robot* Robot);
    void playGame(char a, Robot *Robot, int array[5][5]);
    //get function
    int getNumLives() ;
    int getNumPoints() ;
//    int countNumLives(Robot* Robot);
//    int getXRobot();
//    int getYRobot();
// attributes for stufe 2
    int getGameForGefahren();
    int getGameforBrunnen();
    int getGameForRelikt();
private:

    int numLives;
    int numPoints;


};


#endif //OSENCRAWLERMITKLASSEN_ROBOT_H

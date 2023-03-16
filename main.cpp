#include <iostream>
#include "robot.h"
#include "enemy.h"
#include "linkedlist.h"
#include "generate.h"
using namespace std;

//Movement
//function to control the dummy enemy
//Print map
//function to count point and live
// function to count point (relikt)
//printStat

int main() {

    // for Robot (as the Player)
    Robot Robot;
    // for enemy
     Enemy DummyEnemy;
    // What we need
    int array[5][5];
    char a; // w, a, s or d
    struct node* head = NULL;

    // felder generate
    cout << "\n****** WELCOME PLAYER TO GAME ******\n" << endl;
    int countGame = 0;
    bool game = true;
    // 0 is y, 1 is x
    while(game){
        Robot.pos.x = 0;
        Robot.pos.y = 0;

        cout << "----------------\n" << endl;

        Robot.countGame(countGame, &Robot);// make the game harder by reducing the lives

        if(Robot.getNumLives() <= 0) {
            cout << "\nTry it next time. You are dead" << endl;
            game = false;
        }else{
            generateFelder(array, Robot.pos.y, Robot.pos.x);
        }

        // in game
        while(Robot.getNumLives() > 0){
            cout << "\nWohin willst du gehen: \n" << endl;
            cin >> a;
            Robot.playGame(a, &Robot, array);

            head = add(head, Robot.pos.y, Robot.pos.x, Robot.getNumLives(), Robot.getNumPoints());

            // if player took all the point, we would end the game
            if(Robot.getNumPoints() == c){
                countGame++;
                cout << "***********\n" << endl;
                cout << "Let's make this game more excited" << endl;
                break;
            }
        }
    }
    if(Robot.getNumPoints() <= 0){
        printList(head);
        removeAll(head);
    }
    return 0;
}


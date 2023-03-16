//
// Created by Hiep Le on 25.02.23.
//

#ifndef OSENCRAWLERMITKLASSEN_GENERATE_H
#define OSENCRAWLERMITKLASSEN_GENERATE_H
#include <stdio.h>
#include "felder.h"
#include <time.h>
#include <stdlib.h>

int countPoint(int array[5][5]){
    int sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(array[i][j] == relikt){
                sum++;
            }
        }
    }
    return sum;
}
//Felder
int c;// all the point (relikt) in  game
void generateFelder(int array[5][5], int yPosition, int xPosition){
    srand(time(0));
    int zufall;// for random function
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // i == robot 1 und robot 2
            zufall = rand()%100;
            if(zufall <= 40) {
                array[i][j] = leer;
            }else if(zufall <= 80 ){
                array[i][j] = gefahren;
            }
            else if(zufall <= 90 ){
                array[i][j] = brunnen;
            }else{
                array[i][j] = relikt;
            }

        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
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
    c = countPoint(array);
}
#endif //OSENCRAWLERMITKLASSEN_GENERATE_H

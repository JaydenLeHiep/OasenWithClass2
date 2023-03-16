//
// Created by Hiep Le on 25.02.23.
//

#ifndef OSENCRAWLERMITKLASSEN_LINKEDLIST_H
#define OSENCRAWLERMITKLASSEN_LINKEDLIST_H
#include <stdlib.h>
#include <stdio.h>

// for level 3 , using linked list to print step ....
struct node {
    int yPositionRobot;
    int xPositionRobot;
    int RobotLive;
    int RobotPoint;
//    int yPositionEnemy;
//    int xPositionEnemy;
    struct node* next;
};

struct node* create(int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint){
    struct node* newNode = (struct node*) malloc(sizeof ( struct node));
    newNode->yPositionRobot = yPositionRobot;
    newNode->xPositionRobot = xPositionRobot;
    newNode->RobotLive = RobotLive;
    newNode->RobotPoint = RobotPoint;
//    newNode->yPositionEnemy = yPositionEnemy;
//    newNode->xPositionEnemy = xPositionEnemy;

    return newNode;
}

struct node* addFirst(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint){
    struct node* newHead = create(yPositionRobot, xPositionRobot, RobotLive, RobotPoint);
    newHead->next = head;
    return newHead;
}

struct node* addLast(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint){
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct node* newNode = create(yPositionRobot, xPositionRobot, RobotLive, RobotPoint);
    newNode->next = NULL;
    temp->next = newNode;
    return head;
}
struct node* add(struct node* head, int yPositionRobot, int xPositionRobot, int RobotLive, int RobotPoint){
    if(head == NULL){
        return addFirst(head, yPositionRobot, xPositionRobot, RobotLive, RobotPoint);
    }
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return addLast(head, yPositionRobot, xPositionRobot, RobotLive, RobotPoint);
}

void printList(struct node* head){
    int step = 0;
    while(head != NULL){
        printf("\nStep: %d", step);
        printf("\nPosition of Robot (%d:%d) with %d Lives and %d Point", head->yPositionRobot, head->xPositionRobot, head->RobotLive, head->RobotPoint);

        if(head->next != NULL){
            printf("\n👇👇👇👇");
        }
        step++;
        head = head->next;

    }
}

struct node* removeFirst(struct node* head)
{
    if(head == NULL)
        return head;

    struct node* newHead = head->next;
    free(head);
    return newHead;
}

struct node* removeAll(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        temp = removeFirst(temp);
    }
    return temp;
}





#endif //OSENCRAWLERMITKLASSEN_LINKEDLIST_H

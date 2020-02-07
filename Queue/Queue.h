/*=========================================   QUEUE  ========================================*/
#include "../std_types.h"
#include <stdlib.h>
#define QueueEntry uint16_t

/*---------------------------------------------- Structs ------------------------------------*/
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode * p_nextNode;
}QueueNode;

typedef struct queue
{
    QueueNode * p_front;
    QueueNode * p_rear;
    uint16_t size; 
}Queue;

/*------------------------------------------- Function prototypes ---------------------------*/
/*
*   Description : Intializes Queue
* 
*   @param Queue * q
*
*   @return void
*/
void CreateQueue(Queue * q);

/*
*   Description : Append new element to the queue
*
*   @param QueueEntry e
*   @param Queue * q
*
*   @param uint8_t
*/
uint8_t Enqueue(QueueEntry e , Queue * q);

/*
*   Description : Gets and frees the first element in queue
* 
*   @param QueueEntry * e
*   @param Queue * q
*
*   @return void
*/
void Dequeue(QueueEntry * e , Queue * q);

/*
*   Description : Checks whether Queue is empty or not.
*
*   @param Queue * q
*
*   @return uint8_t
*/
uint8_t QueueEmpty(Queue * q);

/*
*   Description : Checks whether Queue is Full or not.
*
*   @param Queue * q
*   
*   @return 0
*/
uint8_t QueueFull(Queue * q);

/*
*   Description : Gets Queue size.
*
*   @param Queue * q
*
*   @return uint16_t
*/
uint16_t QueueSize(Queue * q);

/*
*   Description : Clears the entire queue
*
*   @param Queue * q
*
*   @return void
*/
void ClearQueue(Queue * q);





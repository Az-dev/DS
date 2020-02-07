/*=========================================   QUEUE  ========================================*/
#include "Queue.h"

/*
*   Description : Intializes Queue
* 
*   @param Queue * q
*
*   @return void
*/
void CreateQueue(Queue * q)
{
    /* Intializes front pointer */
    q->p_front = NULL;
    /* Intializes rear pointer */
    q->p_rear = NULL;
    /* store Queue current size */
    q->size = 0;
}

/*
*   Description : Append new element to the queue
*
*   @param QueueEntry e
*   @param Queue * q
*
*   @param uint8_t
*/
uint8_t Enqueue(QueueEntry e , Queue * q)
{
    /* Create new QueueNode*/
    QueueNode * p_quNode = (QueueNode *)malloc(sizeof(QueueNode));
    /* check if memory allocation succeeded or not */
    if(!p_quNode) return 0;
    else
    {
        /* Insert Element */
        p_quNode->entry = e;
        /* make the newely created node be the last element */
        p_quNode->p_nextNode = NULL;
        /* if the queue was empty : which means q->p_front & q->p_rear == NULL */
        if(!q->p_rear)
        {
            /*make front pointer point to the new node*/
            q->p_front = p_quNode;
        }else{
            /* make the node referenced by rear pointer point to the new node */
            q->p_rear->p_nextNode = p_quNode;
        }     
        /* make rear pointer point to the newely created queue node */
        q->p_rear = p_quNode;
        /*Increament size*/
        q->size++;
        /*retrun 1 to express success*/
        return 1;
    }
}

/*
*   Description : Gets and frees the first element in queue
* 
*   @param QueueEntry * e
*   @param Queue * q
*
*   @return void
*/
void Dequeue(QueueEntry * e , Queue * q)
{    
    /* Create p_temp to point to the node referenced by q->p_front which is the first node*/
    QueueNode * p_temp = q->p_rear;
    /* store node entry in (e)*/
    (*e) = q->p_front->entry;
    /* make q->p_front point to the next element*/
    q->p_front = q->p_front->p_nextNode;    
    /* if the queue was empty : which means q->p_front became null*/
    if(!q->p_front) q->p_rear = NULL;    
    /* free the node */
    free(p_temp);
    /* Decreament size*/
    q->size--;
}

/*
*   Description : Checks whether Queue is empty or not.
*
*   @param Queue * q
*
*   @return uint8_t
*/
uint8_t QueueEmpty(Queue * q)
{
    return !q->p_rear;
}

/*
*   Description : Checks whether Queue is Full or not.
*
*   @param Queue * q
*   
*   @return 0
*/
uint8_t QueueFull(Queue * q)
{
    return 0;   
}

/*
*   Description : Gets Queue size.
*
*   @param Queue * q
*
*   @return uint16_t
*/
uint16_t QueueSize(Queue * q)
{
    return q->size;    
}

/*
*   Description : Clears the entire queue
*
*   @param Queue * q
*
*   @return void
*/
void ClearQueue(Queue * q)
{
    /*While q->p_front != NULL*/
    while(q->p_front)
    {
        /* make rear pointer point to the point after that referenced with front*/
        q->p_rear = q->p_front->p_nextNode;
        /*free the node referenced with front pointer*/
        free(q->p_front);
        /*make front pointer = rear pointer */
        q->p_front = q->p_rear;
    }
    /*Reset Queue size*/
    q->size = 0;
}




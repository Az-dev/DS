/*=========================================   STACK  ========================================*/
#include "../std_types.h"
#include <stdlib.h>
#define StackEntry uint16_t

/*---------------------------------------------- Structs ------------------------------------*/
/* Stack Node */
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode * p_nextNode;
}StackNode;

typedef struct stack
{
    StackNode * p_stackTop;
}Stack;

/*------------------------------------------- Function prototypes ---------------------------*/
/*
*   Description : Intializes p_stackTop to NULL 
*
*   @param Stack * st
*   
*
*   @return void
*/
void CreateStack(Stack * st);

/*
*   Description : Pushes element into the stack
*
*   @param StackEntry element
*   @param Stack st
*
*   @return uint8_t 
*/
uint8_t Push(StackEntry element,Stack * st);

/*
*   Description : Pops element from the stack
*   
*   @param StackEntry* element
*   @param Stack * st
*
*   @return void
*/
void Pop(StackEntry * element , Stack * st);

/*
*   Description : Checks whether stack is empty or not
*   
*   @param Stack * st
*   
*   @return uint8_t
*/
uint8_t StackEmpty(Stack * st);

/*
*   Description : Checks whether stack is full or not
*
*   @param Stack * st
*
*   @return uint8_t
*/
uint8_t StackFull(Stack * st);

/*
*   Description : Clears the entire stack
*
*   @param Stack * st
*
*   @return void
*/
void ClearStack(Stack * st);

/*
*   Description : calculates and returns stack size
*
*   @param Stack * st
*
*   @return uint16_t
*/
uint16_t StackSize(Stack * st);

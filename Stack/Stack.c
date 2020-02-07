/*=========================================   STACK  ========================================*/
#include "Stack.h"

/*
*   Description : Intializes p_stackTop to NULL 
*
*   @param Stack * st
*   
*
*   @return void
*/
void CreateStack(Stack * st)
{
    /*Set (*st).p_stackTop to NULL*/
    st->p_stackTop = NULL;    
}

/*
*   Description : Pushes element into the stack
*
*   @param StackEntry element
*   @param Stack st
*
*   @return uint8_t 
*/
uint8_t Push(StackEntry element,Stack * st)
{
    /* create new stack node */
    StackNode * p_stNode = (StackNode *)malloc(sizeof(StackNode));
    /* check if memory allocation succeeded or not */
    if(!p_stNode) return 0;
    else
    {
        /* insert element */
        p_stNode->entry = element;
        /* assign (st->p_stackTop) to (p_stNode->p_nextNode)*/
        p_stNode->p_nextNode = st->p_stackTop;
        /* make p_stackTop point to the new created stack node */
        st->p_stackTop = p_stNode;
        /*retrun 1 to express success*/
        return 1;
    }
}


/*
*   Description : Pops element from the stack
*   
*   @param StackEntry* element
*   @param Stack * st
*
*   @return void
*/
void Pop(StackEntry * element , Stack * st)
{
    /* retain the data of the node that you want to pop */
    *element = st->p_stackTop->entry;
    /* hold the address of node you want to pop*/
    StackNode * p_temp = st->p_stackTop;
    /* make p_stackTop point to the next node */
    st->p_stackTop = st->p_stackTop->p_nextNode;
    /* free the node that have been already poped*/
    free(p_temp);
}

/*
*   Description : Checks whether stack is empty or not
*   
*   @param Stack * st
*   
*   @return uint8_t
*/
uint8_t StackEmpty(Stack * st)
{
    return (st->p_stackTop == NULL);
}

/*
*   Description : Checks whether stack is full or not
*
*   @param Stack * st
*
*   @return uint8_t
*/
uint8_t StackFull(Stack * st)
{
    /* This function will always return 0 because stack is based on node implementation,-
    *  so there is no fixed value for its size .  
    */
    return 0;
}

/*
*   Description : Clears the entire stack
*
*   @param Stack * st
*
*   @return void
*/
void ClearStack(Stack * st)
{
    StackNode * p_temp = NULL;
    while(st->p_stackTop != NULL)
    {
        /* make p_temp point to the top emlement*/
        p_temp = st->p_stackTop;
        /* make p_stackTop point to the next element*/
        st->p_stackTop = st->p_stackTop->p_nextNode;
        /*clear or free the top node*/
        free(p_temp);
    }
}

/*
*   Description : calculates and returns stack size
*
*   @param Stack * st
*
*   @return uint16_t
*/
uint16_t StackSize(Stack * st)
{
    /* u16_count : is a counter for stack nodes */
    uint16_t u16_count = 0;
    /*Intialize p_temp to point to the top of the stack*/
    StackNode * p_temp = st->p_stackTop;
    while(p_temp != NULL)
    {
        u16_count++;
        p_temp = p_temp->p_nextNode;
    }
    return u16_count;
}







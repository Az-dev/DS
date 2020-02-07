/*=========================================   List  ========================================*/
#include "List.h"


/*
*   Description : Initializes list
*
*   @param List * l
*
*   @return void
*/
void CreateList(List * l)
{
    /* Initialize p_head to null */
    l->p_head = NULL;
    /* Initialize current list size to 0*/
    l->size = 0;
}

/*
*   Description : Checks whether List is empty or not.
*
*   @param List * l
*
*   @return uint8_t
*/
uint8_t ListEmpty(List * l)
{
    return (l->size == 0);
}

/*
*   Description : Checks whether List is Full or not.
*
*   @param List * l
*   
*   @return 0
*/
uint8_t ListFull(List * l)
{
    return 0;
}

/*
*   Description : Gets List size.
*
*   @param List * l
*
*   @return uint16_t
*/
uint16_t ListSize(List * l)
{
    return l->size;
}

/*
*   Description : Clears the entire list
*
*   @param List * l
*
*   @return void
*/
void DestroyList(List * l)
{
    ListNode * p_temp = NULL;
    /*While l->p_head != NULL*/
    while(l->p_head)
    {
        /* Assign (l->p_head) to (p_temp) */
        p_temp = l->p_head;
        /* make (l->p_head) point to the next node */
        l->p_head = l->p_head->p_nextNode;
        /* free the node*/
        free(p_temp); 
    }
    /*Reset List size*/
    l->size = 0;
}


/*
*   Descritpion : Inserts an element into the list.
*   
*   @param List * l
*   @param ListEntry e
*   @param uint16_t pos
*
*   @return uint8_t
*/
uint8_t InsertList(List * l, ListEntry e ,uint16_t pos)
{
    /*Create temp list node and uint16_t i*/
    ListNode * p_temp = l->p_head; uint16_t i =0;
    /* Create new list node */
    ListNode * p_list=(ListNode *)malloc(sizeof(ListNode));
    /* check if memory allocation succeeded or not */
    if(!p_list) return 0;
    else{
        /* Insert element in the newely created node */
        p_list->entry = e;
        /* if the required position to insert element into is position 0 */
        if(pos == 0)
        {
            /* Make p_nextNode of the newely created list point to the node referenced by head*/
            p_list->p_nextNode = l->p_head;
            /* Make the head point to the newely created element */
            l->p_head = p_list;
        }else
        {
            for(; i<(pos-1) ;i++) 
                p_temp = p_temp->p_nextNode;
            /*1 - Make (p_list->p_nextNode) = (p_temp->p_nextNode)*/
            p_list->p_nextNode = p_temp->p_nextNode;
            /*2- Make (p_temp->p_nextNode) = p_list */
            p_temp->p_nextNode = p_list;
        }
        /* Increament size*/
        l->size++;
        /*retrun 1 to express success*/
        return 1;
    }
}


/*
*   Description : Returns a node entry value and Deletes that node from the list.
*
*   @param List * l
*   @param ListEntry * e
*   @param uint16_t pos
*
*   @return void
*/
void DeleteListNode(List * l , ListEntry * e , uint16_t pos)
{
    /*Create a pointer to point to the node@ (pos)*/
    ListNode * p_pos = NULL;
    /*Create temp list node and uint16_t i*/
    ListNode * p_temp = l->p_head; uint16_t i =0;
    /* of position is 0 */
    if(pos == 0)
    {
        /* Retrieve node entry */
        (*e) = l->p_head->entry;
        /* A temp pointer to hold the head pointer value */
        //p_temp = l->p_head;
        /* Make p_head point to the next node */
        l->p_head = l->p_head->p_nextNode;
        /* free the node */
        free(p_temp);
    }else
    {
        for(;i<(pos-1);i++) 
            p_temp = p_temp->p_nextNode;        
        /* Retrieve node entry */
        (*e) = p_temp->p_nextNode->entry;
        /* Make (p_pos) point to the node @ (pos) */
        p_pos = p_temp->p_nextNode;
        /* Make node @ (pos-1) point to the node @ (pos + 1)*/
        p_temp->p_nextNode = p_temp->p_nextNode->p_nextNode;
        /* Free the node @ (pos) */
        free(p_pos);
    }
    /*Decreament size*/
    l->size--;
}


/*
*   Description : retrieves a copy of node entry of the node at the given position.
*   
*   @param List * l
*   @param ListEntry * e
*   @param uint16_t pos
*
*   @return void
*/
void RetrieveElement(List * l , ListEntry * e , uint16_t pos)
{
    /*Create temp list node and uint16_t i*/
    ListNode * p_temp = l->p_head; uint16_t i =0;
    for(;i<pos;i++) 
            p_temp = p_temp->p_nextNode;
    /* Retrieve node entry */
    (*e) = p_temp->entry;
}

/*
*   Description : replaces a node entry at the given position.
*   
*   @param List * l
*   @param ListEntry e
*   @param uint16_t pos
*
*   @return void
*/
void ReplaceElement(List * l , ListEntry e , uint16_t pos)
{
    /*Create temp list node and uint16_t i*/
    ListNode * p_temp = l->p_head; uint16_t i =0;
    for(;i<pos;i++) 
            p_temp = p_temp->p_nextNode;
    /* Replace node entry */
    p_temp->entry = e;
}

/*
*   Description : Searches for a given entry in the list.
*   
*   @param List * l
*   @param ListEntry e
*
*   @return ListNode *
*/
ListNode * SearchIntoList(List * l , ListEntry e)
{
    /*Stores search key node if the key is found or NULL if the key is not found */
    ListNode * p_keyNode = NULL;
    /*Create temp list node and uint16_t i*/
    ListNode * p_temp = l->p_head; uint16_t i = 0;
    while(i < l->size)
    {
        if(p_temp->entry == e)
        {
            /* Assign (p_temp) in (p_keyNode)*/
            p_keyNode = p_temp;
            /* break from the loop*/
            break;
        }
        /* proceed to the next node*/
        p_temp = p_temp->p_nextNode;
        /*Increament i*/
        i++;
    }            
    /* Retrieve p_keyNode */
    return p_keyNode;
}




/*=========================================   List  ========================================*/
#include "../std_types.h"
#include <stdlib.h>
#define ListEntry uint16_t

/*---------------------------------------------- Structs ------------------------------------*/
typedef struct listnode
{
    ListEntry entry;
    struct listnode * p_nextNode;

}ListNode;

typedef struct list
{
    ListNode * p_head;
    uint16_t size;
}List;

/*------------------------------------------- Function prototypes ---------------------------*/
/*
*   Description : Initializes list
*
*   @param List * l
*
*   @return void
*/
void CreateList(List * l);

/*
*   Description : Checks whether List is empty or not.
*
*   @param List * l
*
*   @return uint8_t
*/
uint8_t ListEmpty(List * l);

/*
*   Description : Checks whether List is Full or not.
*
*   @param List * l
*   
*   @return 0
*/
uint8_t ListFull(List * l);

/*
*   Description : Gets List size.
*
*   @param List * l
*
*   @return uint16_t
*/
uint16_t ListSize(List * l);

/*
*   Descritpion : Inserts an element into the list.
*   
*   @param List * l
*   @param ListEntry e
*   @param uint16_t pos
*
*   @return uint8_t
*/
uint8_t InsertList(List * l, ListEntry e ,uint16_t pos);

/*
*   Description : Returns a node entry value and Deletes that node from the list.
*
*   @param List * l
*   @param ListEntry * e
*   @param uint16_t pos
*
*   @return void
*/
void DeleteListNode(List * l , ListEntry * e , uint16_t pos);

/*
*   Description : retrieves a copy of node entry of the node at the given position.
*   
*   @param List * l
*   @param ListEntry * e
*   @param uint16_t pos
*
*   @return void
*/
void RetrieveElement(List * l , ListEntry * e , uint16_t pos);

/*
*   Description : replaces a node entry at the given position.
*   
*   @param List * l
*   @param ListEntry e
*   @param uint16_t pos
*
*   @return void
*/
void ReplaceElement(List * l , ListEntry e , uint16_t pos);


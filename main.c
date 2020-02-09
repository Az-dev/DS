#include <stdio.h>
#include <ctype.h>
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "List/List.h"

/*-------------------------------------------------Structs and Enums -------------------------------*/
typedef enum Symbols
{
    OPEN_PARAN = '(',
    CLOSED_PARAN = ')',
    OPEN_CURLY = '{',
    CLOSED_CURLY = '}',
    OPEN_PRACT = '[',
    CLOSED_PRACT = ']'
}Symbols;

typedef enum MathSymbols
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/'
}MathSymbols;
/*---------------------------------------------- Function Prototypes ------------------------------*/
uint8_t checkForBalancedParantheses(uint8_t * expression);
sint64_t evaluate(uint8_t * expression);
/*---------------------------------------------- main ---------------------------------------------*/

void main(void)
{    
  /*---------------------------------------- Check Balance -----------------------------------*/
  /* Test Cases : expressions*/
  //uint8_t * expression = "{[()]}";
  //uint8_t * expression = "{[(]}";
  //uint8_t * expression = "{[("; 
  //uint8_t * expression = "{[()}";
  //uint8_t * expression = "{[({[(5+3424+032)]})]}";  
  //uint8_t * expression = "{[({[(5+3424+032)])]}";  
  //if(!checkForBalancedParantheses(expression)) printf("Unbalanced\n");
  //else printf("Balanced\n");
  /*----------------------------------------- Evaluate Expression --------------------------------------*/
  /* Test Cases : expressions*/
  //uint8_t * expression = "(5 + 6 + 9)";
  //uint8_t * expression = "((5 + 6) * 10 - 9)";
  //uint8_t * expression = "(((5 + 6) * 10 - 9)/10)";      
  //printf("%ld\n",evaluate(expression));
}
/*---------------------------------------------- Function Definitions ------------------------------*/
sint64_t evaluate(uint8_t * expression)
{
    /*Define variables*/
    uint8_t isFirstOperation = 1;
    sint64_t result = 0;
    uint16_t accumlator = 0;
    QueueEntry op1;
    QueueEntry op2;
    MathSymbols operation;
    /*create calculation queue*/
    Queue operand_q;
    Queue operation_q;
    CreateQueue(&operand_q);
    CreateQueue(&operation_q);
    /* Check Expression for balance*/
    if(checkForBalancedParantheses(expression))
    {
        /*Create and intialize expression scanner*/
        uint8_t * pu8_expressionScanner = expression;
        /*scan till the end of the string*/
        while(*pu8_expressionScanner != '\0')
        {
            /*1 - check digit*/
            if(isdigit(*pu8_expressionScanner))
            {
                /* add to accumlator */
                accumlator = (accumlator * 10) + (*pu8_expressionScanner - '0');                
            }            
            /*2 - check operations*/
            switch (*pu8_expressionScanner)
            {
                case ADD:
                    /* Enqeue the operand */
                    Enqueue(accumlator,&operand_q); 
                    /* Enqeue the operation*/
                    Enqueue(*pu8_expressionScanner,&operation_q);
                    /*Reset Accumlator */
                    accumlator = 0;              
                    break;
                case SUB:
                    /* Enqeue the operand */
                    Enqueue(accumlator,&operand_q); 
                    /* Enqeue the operation*/
                    Enqueue(*pu8_expressionScanner,&operation_q);
                    /*Reset Accumlator */
                    accumlator = 0;               
                    break;
                case MUL:
                    /* Enqeue the operand */
                    Enqueue(accumlator,&operand_q); 
                    /* Enqeue the operation*/
                    Enqueue(*pu8_expressionScanner,&operation_q);
                    /*Reset Accumlator */
                    accumlator = 0;               
                    break;
                case DIV:
                    /* Enqeue the operand */
                    Enqueue(accumlator,&operand_q); 
                    /* Enqeue the operation*/
                    Enqueue(*pu8_expressionScanner,&operation_q);
                    /*Reset Accumlator */
                    accumlator = 0;                
                    break;            
            }          
            /*Increament*/
            pu8_expressionScanner++;
        }
        /*Enqueue last operand*/                
        Enqueue(accumlator,&operand_q);
        /* reset accumlator */ 
        accumlator = 0;        
        /*evaluation loop*/
        while(!QueueEmpty(&operation_q))
        {
            if(isFirstOperation == 1)
            {
                /*Dequeue first operand*/
                Dequeue(&op1,&operand_q);                
                /*clear isFirstOperation*/
                isFirstOperation = 0;
            }else{
                op1 = (StackEntry) result;                
            }
            /*Dequeue operation*/
            Dequeue(&operation,&operation_q);
            /*Dequeue second operand*/
            Dequeue(&op2,&operand_q);
            /*result += apply current operation*/            
            switch (operation)
            {
            case ADD:
                result = (op1 + op2);                                               
                break;
            case SUB:
                result = (op1 - op2);                    
                break;
            case MUL:
                result = (op1 * op2);                    
                break;
            case DIV:
                result = (op1 / op2);                    
                break;         
            } 
        }       
    }    
    /*Return result*/
    return result;
}

uint8_t checkForBalancedParantheses(uint8_t * expression)
{
    /*stores expression state whether balanced or not*/
    uint8_t u8_isBalanced = 0;
    /* Stores the poped element from the stack */
    StackEntry poped_element;
    /*Create and intialize expression scanner*/
    uint8_t * pu8_expressionScanner = expression;
    /*create and initialize symbols stack*/
    Stack symbol;
    CreateStack(&symbol);
    /*loop throught the expression until end of the string*/
    while(*pu8_expressionScanner != '\0')
    {
        switch (*pu8_expressionScanner)
        {
        case OPEN_PARAN:
        case OPEN_CURLY:
        case OPEN_PRACT:
            /*push to the symbols stack*/
            Push((*pu8_expressionScanner),&symbol);            
            break;        
        case CLOSED_CURLY:
            //if(!StackEmpty)
            //{
                /*pop the last pushed symbol*/
                Pop(&poped_element,&symbol);                               
                /* check whether it matches one of the stored symbols in stack or not */
                if(poped_element == OPEN_CURLY) 
                    u8_isBalanced = 1; /*balance match has occured*/                
                else 
                    u8_isBalanced = 0; /* unbalanced*/
            //}
            break;
        case CLOSED_PARAN:
            // if(!StackEmpty)
            // {
                /*pop the last pushed symbol*/
                Pop(&poped_element,&symbol);                                                               
                /* check whether it matches one of the stored symbols in stack or not */
                if(poped_element == OPEN_PARAN)
                    u8_isBalanced = 1; /*balance match has occured*/                
                else 
                    u8_isBalanced = 0; /* unbalanced*/
            // }
            break;
            break;
        case CLOSED_PRACT:            
            //if(!StackEmpty)
            //{
                /*pop the last pushed symbol*/
                Pop(&poped_element,&symbol);                                
                /* check whether it matches one of the stored symbols in stack or not */
                if(poped_element == OPEN_PRACT)
                    u8_isBalanced = 1; /*balance match has occured*/                
                else 
                    u8_isBalanced = 0; /* unbalanced*/
            //}
            break;
        }        
        /* check u8_isBalanced */
        //if(!u8_isBalanced) break; /*this will break the loop in the first occurence of non-balance*/
        /*Increament (pu8_expressionScanner) */        
        pu8_expressionScanner++;
    }
    return u8_isBalanced;
}
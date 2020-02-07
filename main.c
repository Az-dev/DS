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
    /*
    Stack s;
    CreateStack(&s);
    if(!push(e,&s));
    pop(&e,&s);
    */
   /*
   Queue q;
   QueueCreate();
   if(!Enqueue(e,&q));
   */
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
  /*-----------------------------------------------------------------------------------------*/
}


/*---------------------------------------------- Function Definitions ------------------------------*/
sint64_t evaluate(uint8_t * expression)
{
    /*Define variables*/
    uint16_t sum = 0;
    uint8_t operation_count = 0;
    uint8_t operands = 0;
    uint16_t accumlator = 0;
    MathSymbols current_operation;    
    /*create calculation queue*/
    Queue q;
    CreateQueue(&q);
    /* Check Expression for balance*/
    if(checkForBalancedParantheses(expression))
    {
        /*Create and intialize expression scanner*/
        uint8_t * pu8_expressionScanner = expression;
        /*scan digits till the end of the string*/
        while(*pu8_expressionScanner != '\0')
        {
            /*check digit*/
            if(isdigit(*pu8_expressionScanner))
            {
                /* add to accumlator */
                accumlator = (accumlator * 10) + (*pu8_expressionScanner - '0');
                /* increament operands */
                operands++;
            }
            /*check operations*/
            switch (*pu8_expressionScanner)
            {
            case ADD:
                /* Enqeue the operand in accumlator */
                Enqueue(*pu8_expressionScanner,&q);
                /* increament operations count*/
                operation_count++;
                /* store current operation*/
                current_operation = ADD;                
                break;
            case SUB:
                /* Enqeue the operand in accumlator */
                Enqueue(*pu8_expressionScanner,&q);
                /* increament operations count*/
                operation_count++;
                /* store current operation*/
                current_operation = SUB;                
                break;
            case MUL:
                /* Enqeue the operand in accumlator */
                Enqueue(*pu8_expressionScanner,&q);
                /* increament operations count*/
                operation_count++;
                /* store current operation*/
                current_operation = MUL;                
                break;
            case DIV:
                /* Enqeue the operand in accumlator */
                Enqueue(*pu8_expressionScanner,&q);
                /* increament operations count*/
                operation_count++;
                /* store current operation*/
                current_operation = DIV;                
                break;            
            }
            /*check if operation is 1 and operands is 2*/
            if(operation_count == 1 && operands ==2)
            {
                /*Dequeue first operand*/                
                /*Deqeue second operand*/
                /*sum += apply current operation*/

            }


        }

    }

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
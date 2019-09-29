#include "monty.h"

stack_t *global_stack;
/**
* nope - function that does nothing
* @head: pointer to head
* @line: line command is being called from file
* 
*/
void nop(stack_t **head, unsigned int line)
{
    *head = *head;
    line = line;
}
/**
* sub - subtracts top element from 2nd top element of the stack
* @head: ptr to dbl
* @line: line that command is sent from
*/
void sub(stack_t **head, unsigned int line)
{
    if ((*head) != NULL)
    {
        int x = 0;
        while ((*head)->prev != NULL)
            (*head) = (*head)->prev;
        x = (*head)->n;
        pop(&global_stack, line);
        (*head)->n -= x;
        printf("%d", (*head)->n);
    }
}
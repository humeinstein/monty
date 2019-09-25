#include "monty.h"
/**
*
*
*
*/
void pop(**head, unsigned int line)
{
    *temp = *head->next;
    free(*head);
    *head = temp;
}
void push(**head, unsigned int line)
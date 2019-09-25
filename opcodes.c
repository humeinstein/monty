#include "monty.h"
/**
* pop - function that pops node
*
*
*/
void *pop(stack_t **head, unsigned int line)
{
    *temp = *head->next;
    free(*head);
    *head = temp;
    return(NULL)
}
void *push(stack_t **head, unsigned int value, unsigned int line)
{
    *new = *head;
    new->n = value;
    new->next = *head;
    new->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = new;
    *head = new;
}
void *pall(stack_t **head, unsigned int line)
{
    size_t inc;
    inc = 0;

    while (*head)
    {
        inc++
        printf("%d\n", *head->n);
        *head = *head->next;
    }
    return(NULL);
}
void *pint(stack_t **head, unsigned int line)
{
    if (*head != NULL)
    {
        printf("%d", *head->n);
    }
}
void *swap(stack_t **head, unsgined int line)
{
    
}
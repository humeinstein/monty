#include "monty.h"
/**
* pop - function that pops node
*
*
*/
void *pop(stack_t **head, unsigned int line)
{
    stack_t *temp = (*head)->next;
    free(*head);
    (*head) = temp;
    return(NULL);
}
void *push(stack_t **head, unsigned int value, unsigned int line)
{
    stack_t *new = (*head);
    new->n = value;
    new->next = (*head);
    new->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = new;
    (*head) = new;
}
void *pall(stack_t **head, unsigned int line)
{
    size_t inc;
    inc = 0;

    while (*head)
    {
        inc++;
        printf("%d\n", (*head)->n);
        (*head) = (*head)->next;
    }
    return(NULL);
}
void *pint(stack_t **head, unsigned int line)
{
    if ((*head) != NULL)
    {
        printf("%d", (*head)->n);
    }
}
void *swap(stack_t **head, unsigned int line)
{
    int swap = (*head)->n;


}
void *add(stack_t **head, unsigned int line)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return("ERROR FILL IN ERROR CODES");
    }
    int first = (*head)->n;
    *head = (*head)->next;
    int sum = first + (*head)->n;
    return (sum);

}


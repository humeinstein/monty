#include "monty.h"
/**
* pop - function that pops node
*
*
*/
void pop(stack_t **head, unsigned int line)
{
}

void push(stack_t **head, unsigned int value, unsigned int line)
{
    	stack_t *new;
	new = malloc(sizeof(stack_t));
    	new->n = (int)value;

	if (*head == NULL)
		(*head) = new;
	else
	{
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;
			new->next = (*head);
			new->prev = NULL;
			(*head)->prev = new;
			new->n = (int)value;
	}
}

void pall(stack_t **head, unsigned int line)
{
	while ((*head)->prev != NULL)
		(*head) = (*head)->prev;

	while ((*head)->next != NULL)
	{
		printf("%d\n", (*head)->n);
		(*head) = (*head)->next;
	}
		printf("%d\n", (*head)->n);

	while ((*head)->prev != NULL)
		(*head) = (*head)->prev;

}
void pint(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;
	if (*head != NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;

		printf("%d\n", temp->n);
	}
	else
	{
		printf("No stack found\n");
	}
}
void *swap(stack_t **head, unsigned int line)
{
    int swap = (*head)->n;


}
void *add(stack_t **head, unsigned int line)
{
	/*
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return("ERROR FILL IN ERROR CODES");
    }*/
    int first = (*head)->n;
    *head = (*head)->next;
    int sum = first + (*head)->n;
    /*return (sum);*/

}


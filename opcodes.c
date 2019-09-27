#include "monty.h"

/**
 * push - adds a new node to the stack, or creates one if none exists
 * @head: The global stacked
 * @value: The value of the new node
 * @line: The line in the monty file the command was executed on
 */
void push(stack_t **head, char *value, unsigned int line)
{
    	stack_t *new = NULL;

	if ((atoi(value) == 0 && value[0] != 0) || value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(value);

	if (*head == NULL)
		(*head) = new;
	else
	{
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;

		new->next = (*head);
		(*head)->prev = new;
		new->n = atoi(value);
	}
}

/**
 * pall - Prints all elements of the stack
 * @head: The stack to print
 * @line: The line the command was called on
 */
void pall(stack_t **head, unsigned int line)
{
	(void)line;

	if ((*head) != NULL)
	{
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;

		printf("%d\n", (*head)->n);
		while ((*head)->next != NULL)
		{
			(*head) = (*head)->next;
			printf("%d\n", (*head)->n);
		}
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: The stack
 * @line: the line pint was called on
 */
void pint(stack_t **head, unsigned int line)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
		while ((*head)->prev != NULL)
			(*head) = (*head)->prev;

		printf("%d\n", (*head)->n);

}

void pop(stack_t **head, unsigned int line)
{
	stack_t temp;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	while ((*head)->prev != NULL)
		(*head) = (*head)->prev;

	temp = (*head);
	(*head)->next = NULL;
	(*head) = (*head)->next;
	(*head)->prev = NULL;

	free(temp);

}
/*
void *add(stack_t **head, unsigned int line)
{

    if ((*head) == NULL || (*head)->next == NULL)
    {
        return("ERROR FILL IN ERROR CODES");
    }
    int first = (*head)->n;
    *head = (*head)->next;
    int sum = first + (*head)->n;

}
*/

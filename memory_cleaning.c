#include "monty.h"

/**
 * free_2d_array - Used for simplified freeing of 2d arrays
 * @arr: The pointer to free
 */
void free_2d_array(char **arr)
{
	int loop = 0;

	loop = 0;
	while (arr[loop] != NULL)
	{
		free(arr[loop]);
		loop++;
	}
	free(arr);
}

/**
 * free_dlistint - Frees a doubly linked list
 * @head: the list to free
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp = NULL;

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * sizeof_string - Fetches the exact length of a string
 * @str: The string to evaluate
 *
 * Return: The length of the string
 */
int sizeof_string(char *str)
{
	int size_counter = 0;

	size_counter = 0;
	while (str[size_counter] != '\0')
		size_counter++;

	size_counter++;

	return (size_counter);
}


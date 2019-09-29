#ifndef MONTY_H_
#define MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **head, char *value, unsigned int line);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);

void free_stack();
void free_2d_array(char **arr);
int monty(int argc, char **argv);
char **file_to_array(const char *file);
void line_parser(char *line, unsigned int line_num);
int sizeof_string(char *);
char **file_to_2d_array(char *string);
void free_dlistint(stack_t *head);
void nop(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int line);
#endif

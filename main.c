#include "monty.h"
//main argv argc

int main(int argc, char **argv)
{
    //seperate into sep function
    FILE *fptr = fopen(argv[1], "r"); //https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fptr == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fptr)) != -1)
    {
        printf("Retrieved line of length %zu: \n", read);
        printf("%s", line);
    }
    fclose(fptr);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}


/** 
***************COMMANDS********
* push - pushes an element to the stack
    ----push <int>
    ---------if <int> !int | no arg given to push print ERROR:LINE
* pall - prints all the values on the stack
    ---------- prints all the values on the stack starting from the top
        --------if empty print nothing
* pint - prints value at the stop of stack
    -------prints the value at the top of the stack, followed by new line if empty ERROR
* pop - removes the top element of the stack
    ---------- removes the top element of the stack
* swap - swaps the top two elements of the stack if empty print error
* add - adds the top two elements of the stack
* nop - does nothing
*/

//main
/**
* main
* take in monty code
* read 
* parse by '\n' creats list
* while (commands)
* parse to take first 2 ele
* if commant then execute it
*/
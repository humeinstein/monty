#include "monty.h"

/**
 * main - The core of the monty interpretor
 * @argc: THe amount of args
 * @argv: The command line arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	char **file_input;
	int line_count;

	if (argc > 1)
	{

		file_input = file_to_array(argv[1]);

		for (line_count = 0; file_input[line_count] != NULL; line_count++)
			line_parser(file_input[line_count]);


	}
	else
		printf("Error: No input file detected\n");

	return (0);
}


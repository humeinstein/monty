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
	FILE *file;

	line_count = 0;
	file = NULL;
	file_input = NULL;

	if (argc > 1 && argc < 3)
	{
		file = fopen(argv[1], "r");
		if ((file))
		{
			file_input = file_to_array(argv[1]);

			if (file_input != NULL)
				for (line_count = 0; file_input[line_count] != NULL; line_count++)
					line_parser(file_input[line_count], (unsigned int)line_count);

			free_stack();
			free_2d_array(file_input);
			fclose(file);
		}
		else
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}



	return (0);
}


#include "monty.h"

/**
 * file_to_array - converts a file to an array
 * @file: The file to read from
 *
 * Return: an array containing all contents from file
 */
char **file_to_array(const char *file)
{
	char *file_out;
	int file_desc, file_size;
	struct stat st;

	file_desc = open(file, O_RDONLY);

	stat(file, &st);
	file_size = st.st_size;

	file_out = malloc(file_size);

	if (!file_out)
		return (NULL);
	if (file_desc == -1)
		return (NULL);

	read(file_desc, file_out, file_size - 1);
	return (file_to_2d_array(file_out));

}

/**
 * cmd_parser - seperates each parameter into a slot in an array
 * @cmd_to_parse: The command for parse (for ex. "Ls - l")
 *
 * Return: The 2d array for execution
 */
char **file_to_2d_array(char *string_to_parse)
{
	char **parsed_array = NULL;
	char *tok_cmd = NULL, *ptr_origin = NULL;
	int loop = 0, cmd_count = 1;

	while (string_to_parse[loop] != '\0')
	{
		if (string_to_parse[loop] == ' ')
			cmd_count++;
		loop++;
	}

	parsed_array = malloc(cmd_count * sizeof(char *) + 1);

	loop = 0;
	tok_cmd = malloc(sizeof_string(string_to_parse) * sizeof(char));
	strcpy(tok_cmd, string_to_parse);
	ptr_origin = tok_cmd;
	tok_cmd = strtok(tok_cmd, "\n");
	while (tok_cmd != NULL)
	{
		parsed_array[loop] = malloc(sizeof(tok_cmd));
		strcpy(parsed_array[loop], tok_cmd);

		tok_cmd = strtok(NULL, "\n");

		loop++;
	}

	free(ptr_origin);
	free(tok_cmd);

	return (parsed_array);
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
/**
 * line_parser - parser a command line and calls the proper op code
 * @line: The line to parse and execute
 */
void line_parser(char *line)
{
	char *command, *token, *ptr_origin;
	int parameter = -1;

	command = NULL;

	ptr_origin = token;

	token = strtok(line, " ");
	while (token != NULL)
	{
		if ((token[0] > 96 && token[0] < 123) && command == NULL)
			command = token;
		else if (token[0] > 47 && token[0] < 58)
		{
			parameter = atoi(token);
			break;
		}
		token = strtok(NULL, " ");
	}

	printf("%s\n", command);
	printf("%d\n", parameter);

}

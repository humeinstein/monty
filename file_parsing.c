#include "monty.h"

stack_t *global_stack;


/**
 * line_parser - parser a command line and calls the proper op code
 * @line: The line to parse and execute
 * @line_num: The number of the line being executed
 */
void line_parser(char *line, unsigned int line_num)
{
	char *command, *token, *param;
	param = 0;
	
	command = NULL;
	token = strtok(line, " ");
	while (token != NULL)
	{
		if ((token[0] >= 'a' && token[0] <= 'z') && command == NULL)
			command = token;
		else if (atoi(token) != 0 && token[0] != '0')
			param = token;

		token = strtok(NULL, " ");
	}

	
	if (strcmp(command, "push") == 0)
		push(&global_stack, param, line_num);
	else if (strcmp(command, "pall") == 0)
		pall(&global_stack, line_num);
	else if (strcmp(command, "pint") == 0)
		pint(&global_stack, line_num);
	else if (strcmp(command, "pop") == 0)
		pop(&global_stack, line_num);
	else if (strcmp(command, "nop") == 0)
		nop(&global_stack, line_num);
	else if (strcmp(command, "sub") == 0)
		sub(&global_stack, line_num);

}


/**
 * file_to_array - converts a file to an array
 * @file: The file to read from
 *
 * Return: an array containing all contents from file
 */
char **file_to_array(const char *file)
{
	char *file_out, **multi_file_out;
	int file_desc, file_size;
	struct stat st;

	file_out = NULL;
	multi_file_out = NULL;
	file_desc = 0;
	file_size = 0;

	file_desc = open(file, O_RDONLY);

	stat(file, &st);
	file_size = st.st_size;

	file_out = malloc(file_size + 1);

	if (!file_out)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (file_desc == -1)
		return (NULL);

	read(file_desc, file_out, file_size);

	file_out[file_size] = '\0';
	
	multi_file_out = file_to_2d_array(file_out);
	free(file_out);
	return (multi_file_out);
}

/**
 * file_to_2d_array - seperates line into its own slot in the array
 * @string_to_parse: The string to convert to 2d array
 *
 * Return: The 2d array for interpretation
 */
char **file_to_2d_array(char *string_to_parse)
{
	char **parsed_array;
	char *tok_cmd, *ptr_origin;
	int loop, cmd_count;

	parsed_array = NULL;
	tok_cmd = NULL;
	ptr_origin = NULL;
	loop = 0;
	cmd_count = 1;
	while (string_to_parse[loop] != '\0')
	{
		if (string_to_parse[loop] == '\n')
			cmd_count++;
		loop++;
	}
	parsed_array = malloc(cmd_count * sizeof(char *) + 1);
	if (!parsed_array)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	loop = 0;
	tok_cmd = malloc(sizeof_string(string_to_parse) * sizeof(char));
	if (!tok_cmd)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	return (parsed_array);
}

/**
 * free_stack - Frees the global stack, can be called from main
 */
void free_stack(void)
{
	free_dlistint(global_stack);
}

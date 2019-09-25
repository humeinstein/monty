#include "monty.h"
/**
 * file_to_array - converts a file to an array
 * @file: The file to read from
 *
 * Return: an array containing all contents from file
 */
char *file_to_array(const char *file)
{
	char *file_out;
	int file_desc, file_size;

	file_desc = open(file, O_RDONLY);

	struct stat st;
	stat(file, &st);
	file_size = st.st_size;

	file_out = malloc(file_size);

	if (!file_out)
		return (NULL);
	if (file_desc == -1)
		return (NULL);

	return (file_out);

}

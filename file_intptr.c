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
	struct stat st;

	file_desc = open(file, O_RDONLY);

	stat(file, &st);
	file_size = st.st_size;

	file_out = malloc(file_size);

	if (!file_out)
		return (NULL);
	if (file_desc == -1)
		return (NULL);

	read(file_desc, file_out, file_size);

	return (file_out);

}

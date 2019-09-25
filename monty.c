#include "monty.h"

int main(int argc, char *argv[])
{
	char *file_input;

	file_input = file_to_array(argv[1]);

	printf("%s", file_input);

	return (0);
}


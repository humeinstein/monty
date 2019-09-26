#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "test_header.h"

int main(void)
{
	file_to_array("test");
	return 0;
}

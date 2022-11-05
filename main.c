#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}
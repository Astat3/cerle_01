#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	char buff[500];
	int fd = 0;

	fd = open("note.txt", O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE); // pourquoi exit_failur == 1 ?
	while (read(fd, buff, BUFFER_SIZE))
	{
		buff[BUFFER_SIZE] = '\0';
		printf("%s\n", buff);
	}
}
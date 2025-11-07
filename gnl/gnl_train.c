#include "get_next_line.h"
#include <fcntl.h>
int main(void)
{
    char buff[256];
    int bytes;
    int fd = open("note.txt", O_RDONLY);

    bytes = read(fd, buff, 2);
    while (bytes)
    {
        buff[bytes] = '\0';
        printf("buff: %s\n", buff);
        bytes = read(fd, buff, 2);
    }
    
}
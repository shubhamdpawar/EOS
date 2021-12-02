#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fd;
    fd = open("desd.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (-1 == fd)
    {
    perror("Error:\n");
    exit(EXIT_FAILURE);
    }

    write(fd, "DESD", 4);
    close(fd);
    return 0;
}

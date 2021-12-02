#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fdw;
    fdw = open("desd.txt", O_WRONLY);

    if (-1 == fdw)
    {
    perror("Error:\n");
    exit(EXIT_FAILURE);
    }

    write(fdw, "DESD", 4);
    close(fdw);
    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fdr;
    fdr = open("src.txt", O_RDONLY);

    if (-1 == fdr)
    {
    perror("Error:\n");
    exit(EXIT_FAILURE);
    }

    write(fdr, "DESD", 4);
    close(fdr);
    return 0;
}

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    unsigned char buff[16];
    int fd;
    fd = open("desdfifo", O_RDONLY);
    read(fd, buff, 16);
    close(fd);
    return 0;
}
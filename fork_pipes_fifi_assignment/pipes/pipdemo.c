#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    unsigned char buff[16];
    pid_t id;
    int fd[2];
    pipe(fd);

    // fd[0] -> reading end
    // fd[1] -> writing end

id = fork();
if (0 == id)
{
    printf("Child: Reading data\n");
    read(fd[0], buff, 16);
    printf("Child Read: %s\n", buff);
}
else
{
    printf("Parent: Writing data\n");
    write(fd[1], "DESD\n", 5);
    printf("Parent: Writing done\n");
}
    return 0;
}
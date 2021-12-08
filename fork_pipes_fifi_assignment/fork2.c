#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before fork\n");
    id = fork();

    if (0 == id)
{
    printf("char[16]Child: PPID %d\n");
    printf("child: PPID %d\n", getppid());
}
else
{
    printf("Parent: PID %d\n", getpid());
    printf("Parent: PPID %d\n", getppid()); 
    sleep(10);
    printf("Parent finished\n");
}
    return 0;
}
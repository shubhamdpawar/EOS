#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before fork\n");
    id = fork();
    printf("After fork: %d\n", id);

    if (0 == id)
    {
        printf("Child\n");
    }
    else
    {
        printf("Parent\n");
    }
    return 0;
}    

    
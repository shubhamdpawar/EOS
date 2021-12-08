#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    unsigned char buff[16];

    printf("desdshell $ ");
    scanf("%s", buff);

    printf("%s\n", buff);

    printf("Before fork\n");
    id = fork();
    printf("After fork\n");

    if (0 == id) //child
    {
        printf("Child: Before exec\n");
        execl("/home/coderaju/git_workspace/EOS_PROJECT/day5_syscall_pid_desdcp_assignment/PIDs/pid","/home/coderaju/git_workspace/EOS_PROJECT/day5_syscall_pid_desdcp_assignment/PIDs/pid",NULL);
        printf("Child: After exec\n");
    }
    else //Parent
    {
        printf("Parent\n");
    }
    printf("Program exited\n");

    return 0;
}
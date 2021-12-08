#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int agrc, char const *argv[])
{
    pid_t id;
     int x, y, sum=0;
     int arr[2];
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    // fd1[0] , fd2[0] => reading end
    // fd1[1] , fd2[1] => writing end
 
    id = fork();
    if (0 == id)
    {
        close(fd1[1]);
        close(fd2[0]);
           
       read (fd1[0], arr, sizeof(arr));
       printf ("Child process.\n");
       printf("Child Read value of arr[0]= %d\n", arr[0]);
       printf("Child Read value  of arr[1]= %d\n\n", arr[1]);
       sum = arr[0] + arr[1];
        

        write(fd2[1], &sum, sizeof(sum));


    }
    else
    {
        close(fd1[0]);
        close(fd2[1]);
       
        printf("Parent process\n");
        printf ("Enter two the number:");
        scanf ("%d %d", &arr[0], &arr[1]);
        write (fd1[1], arr, sizeof(arr));


        read(fd2[0], &sum, sizeof(sum));  // reading the sum which is sent by child process.
        printf ("Printng of summation done at parent side.\n");
        printf("Sum = %d\n", sum);
    }

}
    
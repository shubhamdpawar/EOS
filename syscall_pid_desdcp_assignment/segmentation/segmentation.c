#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr = 0x2000;
    ptr = (int *)malloc(sizeof(int) * 10);

    printf("addr = %d\n", *ptr);
    return 0;
}
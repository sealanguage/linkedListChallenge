#include <stdio.h>
#include <stdlib.h>

typedef uint_8 BYTE;

BYTE *buffer = malloc(sizeof(BYTE) * 512);

int main(int argc, char *argv[])
{
    int x = 0xa2;
    if(x >= 0xe0 && x <= 0xef)
    {
        printf("The number is within the range 0xe0 and 0xef\n");
    }
    else
    {
        printf("the statement is outside the range\n");
    }
}
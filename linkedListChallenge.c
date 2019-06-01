#include <stdio.h>
#include <stdlib.h>


// struct called node, containting int identified as value, reference to another node identified as next
typedef struct NODE
{
    int value;
    struct NODE *next;
}NODE;


int add(int *x, int y)
{
    *x += 3;
    return *x + y;
}

int main (void)
{
    NODE rootNode;
    rootNode.value = 5;

    NODE secondNode;
    secondNode.value =10;
    rootNode.next = &secondNode;

    printf("%i\n", rootNode.value);
    printf("%i\n", rootNode.next->value);

    // omt a = 5;
    // int b = 10;
    //
}
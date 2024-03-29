#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// struct called node, containting int identified as value, reference to another node identified as next
typedef struct NODE
{
    int value;
    struct NODE *next;
}NODE;

NODE *rootNode;

// initaillize the list
void addNode(int value)
{

    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;

    // NODE *trav = rootNode;
    if(rootNode == NULL)
    {
        rootNode = newNode;
        // return;
    }

    NODE *trav = rootNode;
    // break;
        while(trav->next != NULL)
        {
            trav = trav->next;
        }

}


void displayList(NODE* trav)
{
    // iterate through the list and print each number until it gets to the end.
    // should display 5, 10, 8, 17

    printf("trav->value %i\n", trav->value);   //prints number 5

    while(trav->next != NULL)
    {

        // printf("first %i, ", trav->value);     // not printing right now
        trav = trav->next;
        printf("first %i, ", trav->value);

    }
    // printf("second %i\n", trav->value);     // printing number 5 that's all

    // printf("%i\n", rootNode.next->next->value, rootNode.next->next->next->value);


}


// revmoeNode()
// {
//     printf("xxx");
// }

int main (void)
{
    // NODE rootNode;
    // rootNode.value = 5;
    // rootNode.next = NULL;
    addNode(5);
    addNode(10);
    addNode(8);
    addNode(17);

    // printf(" %i", rootNode->value);

    displayList(rootNode);
    free(rootNode);

}

// the file prints 2 values of 5 but does not iterate through the other values, does not add the other values.
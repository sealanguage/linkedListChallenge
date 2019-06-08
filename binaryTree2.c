#include <stdio.h>
#include <stdlib.h>


// create the NODE for a binary tree
typedef struct NODE
{
    int value;
    struct NODE *low;
    struct NODE *high;
}NODE;


//
NODE* rootNode;

void addNode(int value)
{
    // add node will add a node so create a node to start
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->high = NULL;
    newNode->low = NULL;

    NODE * trav = rootNode;

    if (rootNode == NULL)
    {
        rootNode = newNode;
        printf("Home node is: %i\n", rootNode->value);
        return;
    }
    while(rootNode != NULL)
    {
        if(value > rootNode->value)
        {
            trav = trav->high;
            rootNode = newNode;
            printf("newNode value is %i\n", newNode->value);
        }
        if(value < rootNode->value)
        {
             trav = trav->low;
             rootNode = newNode;
             printf("newNode value is %i\n", newNode->value);
        }
        return;
    }

}

int main(void)
{
    printf("hello\n");
    addNode(10);
    addNode(15);
    addNode(4);


}
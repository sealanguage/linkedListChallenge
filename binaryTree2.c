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



void displayTreeOnEntry(NODE *curNode)
{
    if (curNOde->low != NULL)
    {
        dipslayTreeOnentry(curNode->low);
    }
    if (curNode->high != NULL)
    {
        displayTreeOnEntry(curNode->high);
    }
}


void displayTreeOnDeparture(NODE *curNode)
{

}




int doesContain(int value)
{
    // search the tree
    // return 0 if value is not in the tre
    // return 1 if value does exist in the tree
    return 0;
}

int main(void)
{
    // printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
    ddNode(4);
    addNode(6);
    addNode(7);
    ddNode(9);
    addNode(13);
    addNode(18);
    ddNode(16);
    addNode(11);
    addNode(1);

    displayTreeOnEnter(rootNode);
    printf("\n");
}

// 10  8  15  17  20  18  5  6  9  4  13  7
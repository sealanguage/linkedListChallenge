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

    // if value of new node is less the root node attach to low
    // else add to high.
    while (1)
    {
        if (newNode->value < trav->value)
        {
            if (trav->low == NULL)
            {
                trav->low = newNode;
                return;
            }
            trav = trav->low;
            continue;
        }
        else
        {
             if (trav->high == NULL)
             {
                 trav->high = newNode;
                return;
             }
        trav = trav->high;
        continue;
        }

    }

}



void displayTreeOnEnter(NODE *curNode)
{
    printf("%i ", curNode->value);

    if (curNode->low != NULL)
    {
        displayTreeOnEnter(curNode->low);
    }
    if (curNode->high != NULL)
    {
        displayTreeOnEnter(curNode->high);
    }
}


void displayTreeOnDeparture(NODE *curNode)
{
    while (curNode->low != NULL)
    curNode = curNode->low;

    {
        if (curNode->low == NULL)
        printf("%i ", curNode->value);
        free(curNode);
    }

}




int doesContain(int value)
{
    // search the tree
    // return 0 if value is not in the tree
    // return 1 if value does exist in the tree
    return 0;
}

int main(void)
{
    // printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
    addNode(17);
    addNode(20);
    addNode(18);
    addNode(5);
    addNode(6);
    addNode(9);
    addNode(4);
    addNode(13);
    addNode(7);

    // displayTreeOnEnter(rootNode);

    printf("\n");
    displayTreeOnDeparture(rootNode);
    printf("\n");
}

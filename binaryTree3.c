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

void displayTreeOnExit(NODE *curNode)
{
    printf("%i ", curNode->value);

    if (curNode->low == NULL)
    {
        displayTreeOnEnter(curNode->low);
    }
    if (curNode->high == NULL)
    {
        displayTreeOnEnter(curNode->high);
    }
}


// WORKING ON THIS SECTION NOW ******************************
void displayTreeOnDeparture(NODE *curNode)
{
    NODE * trav = rootNode;
    NODE *temp;
    printf("display DEPARTURE: %i\n", rootNode->value);

    while(trav->low->low != NULL && trav->low->high != NULL)
    {
        trav = trav->low->low;
        // temp = trav->low;
        printf("trav low low %i\n", trav->low->value);
        // trav = temp;
        while(trav->low->low == NULL && trav->high != NULL)
        {
            trav = trav->high->high;
            printf("trav high %i\n", trav->value);
            // free(trav);
        }

    }
    // while(trav->high != NULL)
    // {
    //     trav = trav->high;
    //     printf("trav %i\n", trav->value);
    // }


    printf("end %i\n", trav->value);

    // NODE * trav = rootNode;
    // if (rootNode->low == NULL && rootNode->high == NULL)
    //     {
    //         printf("rootNode value %i ", rootNode->value);
    //         // free(curNode);
    //     }

    // while (curNode->low != NULL)
    // {
    //     curNode = curNode->low;
    // }


}

//  4 7 6 5 9 8 13 18 20 17 15 10



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
    displayTreeOnExit(rootNode);
}

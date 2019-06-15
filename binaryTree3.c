#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define true 1
#define false 0

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
    // printf("%i ", curNode->value);

    if (curNode->low != NULL)
    {
        displayTreeOnEnter(curNode->low);
    }
    if (curNode->high != NULL)
    {
        displayTreeOnEnter(curNode->high);
    }
    printf("%i ", curNode->value);
}

void displayTreeOnDeparture(NODE *curNode)
{





}

//  this should be the final answer:  4 7 6 5 9 8 13 18 20 17 15 10



int doesContain(int value)
{
    // search the tree
    // return 0 if value is not in the tree (false)
    // return 1 if value does exist in the tree (true)

    NODE *trav = rootNode;

    // if (rootNode->value == value)
    // {
    //     printf("rootNode is value");
    //     return 1;
    // }
    while(1)   //  means while true
    {
        if(trav->value == value)
        {
            return 1;
        }
        if (value < trav->value)
        {
            if (trav->low == NULL)
            {
                return 0;
            }
            trav = trav->low;
            continue;    //  nothing below continue will ever run

            // trav = trav->low;
        }
        if(trav->high == NULL)
            {
                return 0;
            }
        trav = trav->high;
        continue;     // not really needed but it makes both blocks look the same
        }
    return 0;

}


// WORKING ON THIS SECTION NOW ******************************
void freeTree(NODE *curNode)
{

    while (rootNode->low->low != NULL)
    {
        NODE *trav = rootNode;
        while(trav->low->low != NULL)
        {
            printf("node value is %i\n", trav->value);
            trav = trav->low;
        }
        printf("%i\n", trav->low->low->value);
        free(trav->low->low);
        trav->low = NULL;

        while(trav->high->high != NULL)
        {
            printf("node value high is %i\n", trav->high->value);
            trav = trav->high->high;
        }
        printf("node value high is %i\n", trav->high->value);
        free(trav->high->high);
        trav->high = NULL;
        continue;
    }
    // free(rootNode);
    return;




        // NODE *trav = rootNode;

        // while (trav->low != NULL)
        // {
        //     printf("trav->low %i\n", trav->low->value);
        //     printf("trav->low->low %i\n", trav->low->low->value);
        //     printf("trav->low->low->low %i\n", trav->low->low->low->value);
        //     trav = trav->low;
        //     printf("trav->low->low %i\n", trav->low->low->value);
        //     free(trav->low->low);
        //     trav->low = NULL;
        //     printf("new trav->low->value %i\n", trav->low->value);
        // }
        // return;
    // }

}


void tests()
{
    assert(doesContain(10) && "tree does contain 10");
    assert(doesContain(8) && "tree does contain 8");
    assert(doesContain(4) && "tree does contain 4");
    assert(!doesContain(1) && "tree does not contain 1");
    assert(doesContain(15) && "tree does contain 15");
    assert(doesContain(13) && "tree does contain 13");
    assert(!doesContain(100) && "tree does not contain 100");
    assert(doesContain(7) && "tree does contain 7");
    assert(!doesContain(16) && "tree does not contain 16");
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


    // assert(!freeTree(4) && "tree does not contain 4");

    // displayTreeOnEnter(rootNode);
    // tests();
    // printf("\n");
    displayTreeOnDeparture(rootNode);
    printf("\n");
    // displayTreeOnExit(rootNode);
    // printf("\n");
    doesContain(2);
    freeTree(rootNode);
}

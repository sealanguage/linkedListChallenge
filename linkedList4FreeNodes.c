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



// initaillize the list
void addNode(int value, NODE *homeNode)
{

    NODE * trav = homeNode;
    while(trav->next != NULL)
    {
        trav = trav->next;
    }
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    trav->next = newNode;
    // break;
        while(trav->next != NULL)
        {
            trav = trav->next;
            // printf("Value = %i\n", value);
            // printf("moved deeper\n");

        }


}


void displayList(NODE* trav)
{
    // iterate through the list and print each number until it gets to the end.
    // should display 5, 10, 8, 17

    printf("%i, ", trav->value);

    while(trav->next != NULL)
    {
        trav = trav->next;
        printf("%i, ", trav->value);
    }
    printf("\n");

    // printf("%i\n", rootNode.next->next->value, rootNode.next->next->next->value);


}

// void removeNode(int value)
// {
//     NODE *trav = rootNode;
//     if(rootNode->value == value)
//     {

//         trav = trav->next
//     }
//     printf("%i\n", trav->value);
// }

void freeList()
{
    // loop through find last item, send value to remove node
    // loop through find second to last remove item, and set to null until only head remains
    // recursively iterate through the list to remove all items

    // printf("free beginning %i\n", trav->value);
    while(rootNode->next != NULL)
    {
        NODE *trav = rootNode;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        printf("%i\n. trav->value");
        free(trav->next);
        trav->next = NULL;
        return;
    }
    free(rootNode);

}


// void freeListFunction()
// {
//     while(rootNode->next != NULL)
//     {
//       NODE *trav = rootNode;
//       while(*trav->next != NULL)
//       {
//           trav = trav->next;

//         printf("travelling %i\n", trav->value);
//       }
//       removeNode(trav->value);

//     }

// }

int main (void)
{
    NODE rootNode;
    rootNode.value = 5;
    rootNode.next = NULL;

    // addNode(10, &rootNode);
    // addNode(8, &rootNode);
    // addNode(17, &rootNode);

    // printf(" %i", rootNode.value);


    // displayList(&rootNode);
    // printf("linkedList4 is working\n");
    freeList(&rootNode);
    void free();
}


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

    // printf("trav->value %i\n", trav->value);

    while(trav->next != NULL)
    {

        printf("%i, ", trav->value);
        trav = trav->next;

    }
    printf("%i\n", trav->value);

    // printf("%i\n", rootNode.next->next->value, rootNode.next->next->next->value);


}


int main (void)
{
    NODE rootNode;
    rootNode.value = 5;
    rootNode.next = NULL;

    addNode(10, &rootNode);
    addNode(8, &rootNode);
    addNode(17, &rootNode);

    // printf(" %i", rootNode.value);


    displayList(&rootNode);
    printf("linkedList2 is working\n");
    void free();
}


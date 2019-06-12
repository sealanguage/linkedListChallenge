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

NODE* rootNode;

// initaillize the list
void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;

    if(rootNode == NULL)
    {
        rootNode = newNode;
        return;
    }
    NODE * trav = rootNode;
    while(trav->next != NULL)
    {
        trav = trav->next;
        // printf("Value = %i\n", value);
        // printf("moved deeper\n");
    }
    trav->next = newNode;

}

void removeNode(int value)
{
    NODE *trav = rootNode;
    if(rootNode->value == value)
    {
        rootNode = rootNode->next;
        free(trav);
        return;
    }
    printf("%i\n", trav->value);
    while(trav->next->value != value)
    {
        trav = trav->next;
    }
    NODE *temp = trav->next;
    trav->next = temp->next;
    free(temp);
}


void displayList()
{
    // iterate through the list and print each number until it gets to the end.
    // should display 5, 10, 8, 17
    NODE* trav = rootNode;
    printf("%i, ", trav->value);

    while(trav->next != NULL)
    {
        trav = trav->next;
        printf("%i, ", trav->value);
    }
    printf("\n");

    // printf("%i\n", rootNode.next->next->value, rootNode.next->next->next->value);


}


// this freeList() doesn't work
// void freeList()
// {
//     // loop through find last item, send value to remove node
//     // loop through find second to last remove item, and set to null until only head remains
//     // recursively iterate through the list to remove all items

//     printf("attempt to free %i\n", curNode->value);
//     if(curNode->next == NULL)
//     {
//         printf("no children freed %i\n", curNode->value);
//         free(curNODE);
//         return;
//     }
//     // if I have a child, iterate through the list to remove all items
//     printf("child found moving to children \n", curNode->value);
//     freeList(curNode->next);
//     // my child freed itself
//     printf("control returned to  %i\n", curNode->value);
//     free(curNode):
//     return;
// }


// freeList efficient remove
void freeListEficientRemoveNode()
{
    NODE *trav = rootNode;
    // err
    while(rootNode == NULL)
    {
        removeNode(rootNode->value);
        printf("removed node value %i\n", rootNode->value);
    }
}

// void freeListSelf()
// {
//     while(rootNode->next != NULL)
//     {
//         NODE *trav = rootNode;
//         while(trav->next->next != NULL)
//         {
//             trav = trav->next;
//         }
//         printf("%i\n. trav->value");
//         free(trav->next);
//         trav->next = NULL;
//         return;
//     }
//     free(rootNode);

// }

void freeListFunction()
{
    while(rootNode->next != NULL)
    {
      NODE *trav = rootNode;
      while(trav->next != NULL)
      {
          trav = trav->next;

        printf("travelling %i\n", trav->value);
      }
      removeNode(trav->value);

    }

}

int main (void)
{
    // NODE rootNode;
    // rootNode.value = 5;
    // rootNode.next = NULL;
    addNode(5);
    addNode(10);
    addNode(8);
    addNode(17);
    displayList();
    // removeNode(17);
    // printf(" %i", rootNode.value);



    // printf("linkedList4 is working\n");
    freeListFunction();
    freeListEficientRemoveNode();
    void free();
}


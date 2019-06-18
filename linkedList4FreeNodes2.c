#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
// void freeListEficientRemoveNode()
// {
//     NODE *trav = rootNode;
//     // err
//     while(rootNode == NULL)
//     {
//         removeNode(rootNode->value);
//         printf("FLERN removed node value %i\n", rootNode->value);
//     }
// }

// void freeListSelf()
// {
//     while(rootNode->next != NULL)
//     {
//         NODE *trav = rootNode;
//         while(trav->next->next != NULL)
//         {
//             trav = trav->next;
//         }
//         printf("%i\n", trav->value);
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

        printf("FLF travelling %i\n", trav->value);
      }
      removeNode(trav->value);

    }

}

//  -------------  WORKING ON THIS SECTION NOW  ------------------
int doesContain(int value)
{
    // search the tree
    // return 0 if value is not in the tree (false)
    // return 1 if value does exist in the tree (true)

    // printf("doesContain is here\n");
    NODE *trav = rootNode;

    if (rootNode->value == value)
    {
        printf("rootNode == value\n");
        return 1;
    }
        printf("trav value is %i\n", trav->value);
        while(value != trav->value)
        {
            trav = trav->next;
            printf("list value is %i\n", trav->value);
            // return 0;
            if (value != trav->value)
            {
                printf("trav value != value %i\n", trav->next->value);
                return 0;
            }
            // if (trav->next == NULL)
            // {
            //     printf("2 not in list\n");
            //     return 0;

            // }
        }
        return 0;
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


    // doesContain(5);
    // doesContain(10);
    // doesContain(8);
    // doesContain(17);
    // assert(doesContain(2) && "tree does not contain 2");
    doesContain(2);
    // printf("linkedList4 is working\n");
            // freeListFunction();
    // freeListEficientRemoveNode();
    void free();
}


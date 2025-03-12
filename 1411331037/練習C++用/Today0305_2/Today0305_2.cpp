#include <stdio.h>
#include <stdlib.h>

// self-referential structure                       
struct listNode {
    int data; // each listNode contains a character 
    struct listNode* nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode* ListNodePtr; // synonym for ListNode

// prototypes
void insert(ListNodePtr* sPtr, int value);
int del(ListNodePtr* sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    int item; // char entered by user

    instructions(); // display the menu
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf_s("%u", &choice, 0);

    // loop while user does not choose 3
    while (choice != 3) {

        switch (choice) {
        case 1:
            printf("%s", "Enter an ID: ");
            scanf_s("\n%d", &item);
            insert(&startPtr, item); // insert item in list
            printList(startPtr);
            break;
        case 2: // delete an element
           // if list is not empty
            if (!isEmpty(startPtr)) {
                printf("%s", "Enter ID to be deleted: ");
                scanf_s("\n%d", &item);

                // if character is found, remove it
                if (del(&startPtr, item)) { // remove item
                    printf("%d deleted.\n", item);
                    printList(startPtr);
                }
                else {
                    printf("%d not found.\n\n", item);
                }
            }
            else {
                puts("List is empty.\n");
            }

            break;
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        } // end switch

        printf("%s", "? ");
        scanf_s("%u", &choice,0);
    }

    puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
    puts("Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to end.");
}

// insert a new value into the list in sorted order
void insert(ListNodePtr* sPtr, int value)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNode)); // create node

    if (newPtr != NULL) { // is space available
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        // loop to find the correct location in the list       
        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr; // walk to ...               
            currentPtr = currentPtr->nextPtr; // ... next node 
        }

        // insert new node at beginning of list
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("%d not inserted. No memory available.\n", value);
    }
}

// delete a list element
int del(ListNodePtr* sPtr, int value)
{
    // delete first node if a match is found
    if (value == (*sPtr)->data) {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return value;
    }
    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr; // walk to ...  
            currentPtr = currentPtr->nextPtr; // ... next node  
        }

        // delete node at currentPtr
        if (currentPtr != NULL) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr)) {
        puts("List is empty.\n");
    }
    else {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}
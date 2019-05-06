#include <stdio.h>
#include <stdlib.h>  

typedef struct node {
    int data; 
    struct node *next;
}Node; 

void createList(Node **refToListHead, int firstData){
    // in this func, we create the first node to the list
    // and put the firstData inside the first node;
    // the listHead is passed in by reference as refToListHead
    // and will be updated upon function end

    printf("creating list...\n");
    Node *newNode = malloc(sizeof(Node));
    newNode->data = firstData;
    newNode->next = NULL;
    
    *refToListHead = newNode; // refToListHead points to listHead
    printf("address stored in refToListHead is %p\n", refToListHead);
    printf("address stored in *refToListHead is %p\n", refToListHead);

}

void insertToStart(Node **refToListHead, int dataToInsert){
    // we will insert the dataToInsert to start of the list
    Node *originalListHead;
    originalListHead = *refToListHead;
    
    // INSERT YOUR CODE HERE!
    
}

void printList(Node* listHead){
    printf("printing list: ");
    Node *current = listHead;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    
    Node *myHead = NULL; // head of the linked list, not really MY HEAD!
    printf("address stored in myHead is %p\n", myHead);
    createList(&myHead, 2018);
    printf("address stored in myHead is %p\n", myHead);
    printList(myHead);
    insertToStart(&myHead, 2020);
    insertToStart(&myHead, 1900);
    printList(myHead);
    
    return 0;
    
}



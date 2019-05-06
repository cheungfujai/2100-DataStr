#include <stdio.h>
#include <stdlib.h>  // <--- remember this

typedef struct node {
    int data; // just generic, meaningless data!
    struct node *next;
    struct node *prev;
} Node;

Node* insert(Node* listHead, int dataToInsert) {
    // we need to return a new head of linkedlist because 
    // the head may change after insertion
    if (listHead == NULL) {
        // list is emtpy, let's insert our first element!
        printf("inserting first element with data %d\n",dataToInsert);
        Node *newNode = malloc(sizeof(Node));
        newNode->data = dataToInsert;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    } else {
        // list is not empty, let's insert at the end
        printf("inserting element with data %d\n",dataToInsert);
        Node *current = listHead;  // CAUTION!
        while (current != NULL) {
            if (current->next == NULL) {
                // if it's end of list...
                Node *newNode = malloc(sizeof(Node));
                newNode->data = dataToInsert;
                newNode->next = NULL;
                current->next = newNode;
                current->next->prev = current;
                return listHead;
            } else {
                // otherwise...
                current = current->next;
            }
        }
    }
    
}

void printList(Node* listHead) {
    printf("printing list: ");
    Node *current = listHead;
    while (current != NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void printCount(Node* listHead) {
    printf("printing count: ");
    // TODO: implement 
    Node *current;
    current = listHead;
    int count = 0;
    while (current != NULL){
        count++;
        current = current->next;
    }
    printf("%d\n", count);
}

Node* deleteFromList(Node *listHead, int dataToDelete) {
    // assume data to delete always exist and is always unique in
    // this exercise
    
    printf("deleting %d from list \n"); 
    Node *current;
    current = listHead;
    while (current->data != dataToDelete){
        current = current->next;
    }
    
    if (current->prev == NULL){
        current->next->prev = NULL;
        listHead = current->next;
    }else if (current->next == NULL){
        current->prev->next == NULL;
    }else {
    current->prev->next = current->next;
    current->next->prev = current->prev;
    }
    
    // TODO: implement!
    
    return listHead;
}

Node* printInReverse(Node* listHead) {
    printf("printing list in reverse: ");
    
    // TODO: implement!
    // HINT: traverse to the end and start from there...
    
    Node *current;
    current = listHead;
    
    while(current->next != NULL){
        current = current->next;
    }
    
    printf("%d", current->data);
    
    while(current->prev != NULL){
            current = current->prev;
            printf(" %d", current->data);
    }
    
    printf("\n");
}

int main()
{   
    Node *myHead = NULL;  
    // head of the linked list, not really MY HEAD!
    myHead = insert(myHead, 2018);
    
    printList(myHead);
    myHead = insert(myHead, 2001);
    myHead = insert(myHead, 1998);
    myHead = insert(myHead, 1999);
    myHead = insert(myHead, 2020);
    printList(myHead);
    printCount(myHead);
    myHead = deleteFromList(myHead, 1998);
    printList(myHead);
    myHead = deleteFromList(myHead, 2018);
    printList(myHead);
    printInReverse(myHead);
    
    return 0;
}

    
    
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;   // stack data, we assume integer for simplicity
  int top;     // top of the stack
  int maxSize; // max size of the stack
} Stack;

void StackInit(Stack* stack, int size) {
    // this function initializes a stack for first use
    printf("Initializing stack to hold %d integers...\n",size);
    stack->maxSize = size;
    stack->top = -1;
    stack->data = (int*) malloc(sizeof(int) * size);
}

void StackPush(Stack* stack, int data) {
    if (stack->top >= stack->maxSize - 1) {
        printf("Stack already full, returning\n");    
        return;
    }
    printf("Pushing %d\n",data);
    
    stack->top++;
    stack->data[stack->top] = data;
}

int StackPeek(Stack* stack) {
    
    // return what's on the top without removing
    
    // TODO: implement
    
    stack = stack->data[stack->top];
}

int StackPop(Stack* stack) {
    
    // return what's on the top and remove it 
    
    // TODO: implement
    
    stack = stack->data[stack->top--];
    
}

int StackDestroy(Stack* stack) {
    // free up memory used up by data
    
    // TODO: implement
}

int main()
{
    Stack myStack;
    
    StackInit(&myStack,8);
    StackPush(&myStack,3);
    StackPush(&myStack,4);
    StackPush(&myStack,6);
    StackPush(&myStack,1);
    printf("Peek: %d\n",StackPeek(&myStack));
    StackPush(&myStack,2);
    StackPush(&myStack,5);
    StackPush(&myStack,8);
    StackPush(&myStack,9);
    StackPush(&myStack,7);
    printf("Peek: %d\n",StackPeek(&myStack));
    printf("Pop: %d\n",StackPop(&myStack));
    printf("Pop: %d\n",StackPop(&myStack));
    printf("Pop: %d\n",StackPop(&myStack));
    printf("Pop: %d\n",StackPop(&myStack));
    StackPush(&myStack,11);
    StackPush(&myStack,10);
    printf("Peek: %d\n",StackPop(&myStack));
    StackDestroy(&myStack);
    
    return 0;
}
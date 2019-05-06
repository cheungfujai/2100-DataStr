#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *circularArray;
    int maxSize;     // max size of queue; size of circular array
    int frontIndex;  // index of the front of queue
    int rearIndex;   // index of the end of queue
    int queueLength; // lenght of queue at the moment; 0 means no one is in queue
} Queue;

void QueueInit(Queue* queue, int size) {
    printf("Initializing queue of max size %d\n",size);
    
    queue->circularArray = (int*) malloc(sizeof(int) * size);
    queue->maxSize = size;
    queue->frontIndex = 0;
    queue->rearIndex = -1;
    queue->queueLength = 0;
}

void Enqueue(Queue* queue, int data) {
    printf("Enqueueing %d\n",data);
    
    // TODO: implement
    // if queue is full, print "Queue full!" and do not enqueue
    
    
    if(queue->queueLength < queue->maxSize){
        queue->circularArray[++(queue->rearIndex) % (queue->maxSize)] = data;
        queue->queueLength++;
    }else if(queue->queueLength >= queue->maxSize){
        printf("Queue full!\n");
    }
    
    
    
}

int Dequeue(Queue* queue) {
    // TODO: implement
    // if queue is empty, print "Queue empty!" and return -1
    
    queue->frontIndex = (queue->frontIndex+1) % (queue->maxSize);
    
    if(queue->queueLength == 0){
        printf("Queue empty!\n");
        return -1;
    }
    queue->queueLength--;
    return queue->circularArray[(queue->frontIndex-1+queue->maxSize)%(queue->maxSize)];
    
}

void QueuePrint(Queue* queue) {
    printf("Print queue: ");
    if (queue->queueLength == 0) {
        printf("(empty)\n");
        return;
    } else if (queue->queueLength <0) {
        printf("Queue length is negative! Something's wrong!\n");
        return;
    }
    
    int i;
    for (i=0;i<queue->queueLength;i++) {
        int circularIndex = (queue->frontIndex+i)%queue->maxSize;
        printf("%d ",queue->circularArray[circularIndex]);
    }
    printf("\n");
}

int main()
{
    Queue myQueue;
    
    QueueInit(&myQueue,6);
    QueuePrint(&myQueue);
    Enqueue(&myQueue,10);
    QueuePrint(&myQueue);
    Enqueue(&myQueue,11);
    Enqueue(&myQueue,12);
    Enqueue(&myQueue,13);
    Enqueue(&myQueue,14);
    Enqueue(&myQueue,15);
    Enqueue(&myQueue,16);
    QueuePrint(&myQueue);
    int i;
    for (i=0;i<4;i++) {
        int result = Dequeue(&myQueue);
        if (result != -1)
            printf("Dequeueing %d\n",result);
    }
    QueuePrint(&myQueue);
    Enqueue(&myQueue,16);
    for (i=0;i<5;i++) {
        int result = Dequeue(&myQueue);
        if (result != -1)
            printf("Dequeueing %d\n",result);
    }
    QueuePrint(&myQueue);
}

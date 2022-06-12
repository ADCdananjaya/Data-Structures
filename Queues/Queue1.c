//contiguous implementation
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 20
typedef int QueueElements;

typedef struct {
    QueueElements items[MAX];
    int front;
    int rear;
    int count;
}Queue;

void main(){
    Queue newQueue, *queuePointer = &newQueue;

    void createQueue(Queue *);
    bool isQueueEmpty(Queue *);
    bool isQueueFull(Queue *);
    void append(Queue *, int );
    void serve(Queue *, int *);

    createQueue(queuePointer);
    printf("is Queue Empty? %d\n",isQueueEmpty(queuePointer));
    printf("is Queue Full? %d\n",isQueueFull(queuePointer));

    append(queuePointer, 5);
    append(queuePointer, 8);
    append(queuePointer, 20);

    printf("is Queue Empty now? %d\n",isQueueEmpty(queuePointer));
    printf("is Queue Full now? %d\n",isQueueFull(queuePointer));

    int servedItem, *ptr2 = &servedItem;

    for(int i=0; i<3; i++){
        serve(queuePointer, ptr2);
        printf("%d\n",servedItem);
    }

    printf("is Queue Empty now? %d\n",isQueueEmpty(queuePointer));
    printf("is Queue Full now? %d\n",isQueueFull(queuePointer));

}

void createQueue(Queue *newQueue){
    newQueue->count = 0;
    newQueue->front = 0;
    newQueue->rear = -1;
}

bool isQueueEmpty(Queue *newQueue){
    if(newQueue->front > newQueue->rear)
        return true;
    else
        return false;
}

bool isQueueFull(Queue *newQueue){
    if(newQueue->rear == MAX-1)
        return true;
    else
        return false;
}

void append(Queue *newQueue, int element){
    if(isQueueFull(newQueue)){
        printf("Queue is full!\n");
        exit(1);
    }
    else{
        newQueue->items[++newQueue->rear] = element;
        newQueue->count++;
    }
}

void serve(Queue *newQueue, int *servedElement){
    if(isQueueEmpty(newQueue)){
        printf("Queue is empty!\n");
        exit(1);
    }
    else{
        *servedElement = newQueue->items[(newQueue->front)++];
        newQueue->count--;
    }
}
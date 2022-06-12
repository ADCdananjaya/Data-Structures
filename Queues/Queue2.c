//linked implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QueueElement;

typedef struct node{
    QueueElement entry;
    struct node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
    int count;
    bool isFull;
}Queue;

void main(){
    Queue newQueue;
    void createQueue(Queue *);
    bool isQueueEmpty(Queue *);
    bool isQueueFull(Queue *);
    void serve(Queue *, QueueElement *);
    void append(Queue *, QueueElement );

    createQueue(&newQueue);

    printf("Is Queue Empty? %s\n", isQueueEmpty(&newQueue)?"True":"False");
    printf("Is Queue Full? %s\n", isQueueFull(&newQueue)?"True":"False");

    append(&newQueue, 5);
    append(&newQueue, 14);
    append(&newQueue, 9);

    printf("Is Queue Empty now? %s\n", isQueueEmpty(&newQueue)?"True":"False");
    printf("Is Queue Full now? %s\n", isQueueFull(&newQueue)?"True":"False");

    int servedItem;
    serve(&newQueue, &servedItem);
    printf("served item1: %d\n", servedItem);

    serve(&newQueue, &servedItem);
    printf("served item2: %d\n", servedItem);

    serve(&newQueue, &servedItem);
    printf("served item3: %d\n", servedItem);

    printf("Is Queue Empty? %s\n", isQueueEmpty(&newQueue)?"True":"False");
    printf("Is Queue Full? %s\n", isQueueFull(&newQueue)?"True":"False");
}

void createQueue(Queue *myQueue){
    myQueue->front = myQueue->rear = NULL;
    myQueue->count = 0;
    myQueue->isFull = false;
}

bool isQueueFull(Queue *myQueue){
    return (myQueue->front == NULL && myQueue->rear == NULL);
}

bool isQueueEmpty(Queue *myQueue){
    return (myQueue->count == 0);
}

void serve(Queue *myQueue, QueueElement *servedElement){
    if(isQueueEmpty(myQueue)){
        printf("Queue is Empty!\n");
        exit(1);
    }
    else{
        Node *newNode;
        *servedElement = myQueue->front->entry;
        newNode = myQueue->front;
        myQueue->front = myQueue->front->next;
        myQueue->count--;
        if(myQueue->front == NULL)
            myQueue->rear == NULL;
        free(newNode);
    }
}

void append(Queue *myQueue, QueueElement appendItem){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("not enough memory!\n");
        myQueue->isFull = true;
        exit(1);
    }
    else{
        newNode->entry = appendItem;
        newNode->next = NULL;
        if(isQueueEmpty(myQueue)){
            myQueue->front = myQueue->rear = newNode;
        }
        else{
            myQueue->rear->next = newNode;
            myQueue->rear = newNode;
        }
        myQueue->count++;
    }
}
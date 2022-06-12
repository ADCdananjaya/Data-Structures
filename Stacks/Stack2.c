//linked implementation 
#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct node{
    int entry;
    struct node *next;
}Node;

typedef struct{
    int noElements;
    int isFull;
    Node *top;
}stack;

void main(){
    void createStack(stack *);
    int isStackEmpty(stack *);
    int isStackFull(stack *);
    void push(int , stack *);
    void pop(int *, stack *);
    void destroyStack(stack *);

    stack myStack;
    createStack(&myStack);
    
    printf("Is stack empty? %d\n", isStackEmpty(&myStack));
    printf("Is stack Full? %d\n", isStackFull(&myStack));

    push(5, &myStack);
    push(14, &myStack);
    push(9, &myStack);
    
    int popedItem;
    pop(&popedItem, &myStack);
    printf("poped item1: %d\n", popedItem);

    pop(&popedItem, &myStack);
    printf("poped item2: %d\n", popedItem);

    pop(&popedItem, &myStack);
    printf("poped item3: %d\n", popedItem);

    printf("Is stack empty now? %d\n", isStackEmpty(&myStack));
    printf("Is stack Full now? %d\n", isStackFull(&myStack));
    
    destroyStack(&myStack);
    
}

void createStack(stack *s){
    s->top = NULL;
    s->noElements = 0;
    s->isFull = 0;
}

int isStackEmpty(stack *s){
    return (s->top== NULL) ? True : False;
}

int isStackFull(stack *s){
    return (s->isFull) ? True : False;
}

void pop(int *item, stack *s){
    Node *np;
    
    *item = s->top->entry;
    np = s->top;
    s->top = s->top->next;
    s->noElements--;
    free(np);
}

void push(int item, stack *s){
    Node *np = (Node *)malloc(sizeof(Node));

    if(np == NULL){
        printf("Not enough memory!\n");
        s->isFull = 1;
    }
    else{
        np->entry = item;
        np->next = s->top;
        s->top = np;
        s->noElements++;
    }
}

void destroyStack(stack *s){
    free(s);
}
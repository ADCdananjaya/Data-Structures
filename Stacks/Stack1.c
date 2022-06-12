//contiguous implementation
#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 20
#define True 1
#define False 0

typedef struct{
    int top;
    int myStack[MAXSTACK];
}stack;

void main(){
    stack *s, stack1;
    int removeItem;
    s = &stack1;

    void createStack(stack *);
    int isStackEmpty(stack *);
    int isStackFull(stack *);
    void push(int, stack *);
    void pop(int *, stack *);
    void printStackElements(stack *);

    createStack(s);

    //Adding elements to the stack
    int array[5] = {5,23,9,19,4};
    for(int i=0; i<5; i++){
        push(array[i],s);
    }

    //deleting array elements
    for(int i=0; i<5; i++)
        array[i] = 0;

    printStackElements(s);

    //pop all elements
    int backup;
    for(int i=0; i<5; i++){
        pop(&backup, s);
        array[i] = backup;
    }

    printStackElements(s);
    printf("Is stack empty? %d\n", isStackEmpty(s));
    printf("Is stack Full? %d\n", isStackFull(s));

}

void createStack(stack *stack1){
    stack1->top = -1;
}

int isStackEmpty(stack *stack1){
    return (stack1->top == -1) ? True : False;
}

int isStackFull(stack *stack1){
    return (stack1->top == MAXSTACK-1) ? True : False;
}

void push(int item, stack *stack1){
    if(!isStackFull(stack1)){
        stack1->myStack[++stack1->top] = item;
    }
    else{
        printf("Stack is Full!\n");
        exit(1);
    }
}

void pop(int *item, stack *stack1){
    if(!isStackEmpty(stack1)){
        *item = stack1->myStack[stack1->top--];
    }
    else{
        printf("Stack is Empty!\n");
        exit(1);
    }
}

void printStackElements(stack *stack1){
    printf("Stack elements: ");
    for(int i=0; i<=stack1->top; i++)
        printf("%d ",stack1->myStack[i]);
    printf("\n");
}
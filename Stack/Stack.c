#include<stdio.h>

#define MAX_VALUE 5          /// Last in First Out (LIFO)

typedef struct
{
    int top;
    int data[MAX_VALUE];
}stack;

void push(stack *ob, int item)
{
    if(ob->top >= MAX_VALUE){
        printf("Stack is Full\n");
        return ;
    }
    ob->data[ob->top++] = item;
}

int pop(stack *ob)
{
    if(ob->top == 0){
        printf("Stack Is Empty\n");
        return ;
    }

    ob->top--;

    return ob->data[ob->top];
}

int main()
{
    stack ob;

    ob.top = 0;

    push(&ob, 10);
    push(&ob, 20);
    push(&ob, 30);
    push(&ob, 40);
    push(&ob, 50);
    push(&ob, 60);

    for(int i=0; i<5; i++)
        printf("%d : %d\n", i, pop(&ob));

    return 0;
}
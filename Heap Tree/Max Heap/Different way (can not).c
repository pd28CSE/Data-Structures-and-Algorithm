#include<stdio.h>

#define MAX 6

int queue_array [MAX];
int front = -1;
int rear = -1;



void insert ();
void delete ();
void display ();
void isFull();
void isEmpty();



int main()
{
    int choice;
    while (1)
    {
        printf ("1. Insert an element into the queue \n");
        printf ("2. Delete an element from the queue \n");
        printf ("3. Display the front element of queue \n");
        printf ("4. Is the queue full \n");
        printf ("5. Is the queue empty \n");
        printf ("6. Quit \n");
        printf ("Enter your choice \n");
        scanf ("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            isFull();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            exit(1);
        default:
            printf ("Wrong Choice!!!!!!");
        }
    }
}
void insert()
{
    int item;
    if ((front == 0 && rear == MAX -1) || (front == rear + 1))
    {
        printf ("Queue is full \n");
        return;
    }
    else
    {
        printf ("Please enter a number \n");
        scanf ("%d", & item);
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1)
            rear = 0;
        else rear = rear + 1;
        queue_array [rear] = item;
    }
}
void delete()
{
    int item;
    if (front == -1)
    {
        printf ("Queue is empty");
        return;
    }
    else
    {
        item = queue_array [front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == MAX -1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    printf ("Front Element: %d \n", queue_array[front]);
}
void isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf ("Queue is full \n");
    }
    else
        printf ("Queue is not full \n");
}
void isEmpty()
{
    if (front == -1)
    {
        printf ("queue is empty \n");
    }
    else
    {
        printf ("queue is not empty \n");
    }
}

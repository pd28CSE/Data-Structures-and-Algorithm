#include<stdio.h>

#define size 5
                                        /// First in First Out (FIFO)
typedef struct 
{
    int ara[size+1];
    int tail, head;
}queqe;

void enqueqe(queqe *obj, int data);  // push
int dequeqe(queqe *obj);  // pop


int main()
{
    queqe obj;

    obj.tail = 0;
    obj.head = 0;

    enqueqe(&obj, 10);
    enqueqe(&obj, 20);
    enqueqe(&obj, 30);
    enqueqe(&obj, 40);
    enqueqe(&obj, 50);
    enqueqe(&obj, 60);

    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n\n", dequeqe(&obj));

    printf("head : %d,   tail : %d\n\n\n\n", obj.head, obj.tail);






    enqueqe(&obj, 11);
    printf("head : %d,   tail : %d\n\n\n\n", obj.head, obj.tail);
    enqueqe(&obj, 12);
    enqueqe(&obj, 13);

    printf("%d\n", dequeqe(&obj));
    printf("head : %d,   tail : %d\n", obj.head, obj.tail);
    printf("%d\n", dequeqe(&obj));
    printf("%d\n\n", dequeqe(&obj));

    printf("head : %d,   tail : %d\n\n\n\n", obj.head, obj.tail);





    enqueqe(&obj, 21);
    enqueqe(&obj, 22);
    enqueqe(&obj, 23);
    enqueqe(&obj, 24);
    printf("head : %d,   tail : %d\n", obj.head, obj.tail);
    enqueqe(&obj, 25);
    enqueqe(&obj, 26);

    printf("head : %d,   tail : %d\n\n\n", obj.head, obj.tail);


    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));
    printf("%d\n", dequeqe(&obj));

    printf("head : %d,   tail : %d\n\n\n", obj.head, obj.tail);

    




    return 0;
}

void enqueqe(queqe *obj, int data)
{
    if((obj->tail + 1) % (size+1) == obj->head){
        printf("Queqe is Full\n");
        return ;
    }

    obj->ara[obj->tail] = data;
    obj->tail = (obj->tail + 1) % (size + 1);
}

int dequeqe(queqe *obj)
{
    int data;

    if(obj->head == obj->tail){
        printf("Queqe is Empty\n");
        return -1;
    }

    data = obj->ara[obj->head];
    obj->head = (obj->head + 1) % (size + 1);


    return data;
}
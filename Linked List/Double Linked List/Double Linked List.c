#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *pre, *next;
};


Node* create_node(int data, Node *pre, Node *next);
void print_linked_list(Node *head);
void print_reverse_linked_list(Node *head);
void  append(int data, Node *head);
Node* prepend(int data, Node *head);
Node* remove_node(Node *head, Node *node);


int main()
{
    Node *head, *p, *q;

    head =  create_node(10, NULL, NULL);
    append(20, head);
    append(30, head);
    append(40, head);
    head = prepend(2, head);
    append(50, head);
    append(60, head);
    head = prepend(1, head);
    head = prepend(0, head);
    append(70, head);



//    print_linked_list(head);
//    for(p=head; p != NULL; p=p->next)
//        q = p;
//
//    print_reverse_linked_list(q);  // print reverse linked list


    print_linked_list(head);

    for(p=head; p != NULL; p=p->next)
        q = p;
    printf("%d\n", q->data);
    head = remove_node(head, q); /// last node remove problem.

    for(p=head; p != NULL; p=p->next)
        q = p;
    print_reverse_linked_list(q);  // print reverse linked list




    return 0;
}


Node* create_node(int data, Node *pre, Node *next)
{
    Node *new_node, *current_node;

    new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->pre = pre;
    new_node->next = next;

    return new_node;
}


void print_linked_list(Node *head)
{
    Node *p;

    for(p = head; p != NULL; p = p->next)
        printf("%d  ", p->data);
    printf("\n\n");
}


void print_reverse_linked_list(Node *head)
{
    Node *p;

    for(p = head; p != NULL; p = p->pre)
        printf("%d  ", p->data);
    printf("\n\n");
}


void  append(int data, Node *head)
{
    Node *new_node, *current_node, *p;

    for(current_node=head; current_node->next != NULL; current_node = current_node->next);

    new_node =  create_node(data, current_node, NULL);
    current_node->next = new_node;
}


Node* prepend(int data, Node *head)
{
    Node *new_node;

    new_node =  create_node(data, NULL, head);
        /// <<<=====              Next line ais same.      <<<<========================
    head->pre = new_node;
  // new_node->next->previous = new_node;

    return new_node;
}


Node* remove_node(Node *head, Node *node)
{
    Node *pre_node, *next_node;

    if(head == node){
        head = node->next;
        head->pre = NULL;
        free(node);
        return head;
    }
    else{
        pre_node = node->pre;
        next_node = node->next;

        pre_node->next = next_node;
        next_node->pre = pre_node;
    }


    free(node);
    return head;
}

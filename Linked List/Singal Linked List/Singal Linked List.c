#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node* Create_Node(int item, Node* next);
void print_linked_list(Node *head);
void Append_Node(Node* head, int item);
Node* Prepand(int data, Node *head);
Node* remove_node(Node *head, Node *node);


int main()
{
    Node *head, *p, *q;

    head = Create_Node(11, NULL);  //  "head" is head node.
    Append_Node(head, 12);
    Append_Node(head, 13);
    head = Prepand(10, head);  // now "head" is head node.
    Append_Node(head, 14);
    Append_Node(head, 15);
    Append_Node(head, 16);

    print_linked_list(head);


    head = Prepand(1, head);  // now "head" is head node.
    print_linked_list(head);


    head = remove_node(head, head->next->next); // remove a node
    head = remove_node(head, head); // remove a node

    print_linked_list(head);


    return 0;
}


Node* Create_Node(int item, Node* next)
{
    Node *new_node;

    new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error");
    }


    new_node->data = item;
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


void Append_Node(Node* head, int item)
{
    Node *new_node, *current_node;

    current_node = head;
    new_node = Create_Node(item, NULL);

    while(current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = new_node;
}


Node* Prepand(int data, Node *head)
{
    Node *new_node, *current_node;


    new_node = Create_Node(data, head);

    return new_node;
}


Node* remove_node(Node *head, Node *node)
{
    Node *current_node, *p;

    current_node = head;

    if(current_node == node){
        current_node = node->next;
        free(node);
        return current_node;
    }


    while(current_node != NULL){
        if(current_node->next == node)
            break;
        current_node = current_node->next;
    }

    current_node->next = node->next;
    free(node);


    return head;
}

#include<iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *left_node, *right_node;
};

Node* create_node(int data);
Node* create_tree();
void add_left_node(Node *root, Node *node);
void add_right_node(Node *root, Node *node);
void print_pre_order(Node *head);
void print_in_order(Node *head);
void print_post_order(Node *head);


int main()
{
    Node *head, *p, *q;

    head= p = q = create_tree();

    print_pre_order(head);
    cout << endl << endl;
    print_in_order(p);
    cout << endl << endl;
    print_post_order(q);

    return 0;
}


Node* create_node(int data)
{
    Node *new_node;
    
    new_node = new Node;
    if(new_node == NULL){
        cout << "Error" << endl;
        return NULL;
    }
    new_node->data = data;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}


Node* create_tree()
{
    Node *head, *seven, *nine, *one, *six, *eight, *five, *ten, *three, *four;

    head = create_node(2);
    seven = create_node(7);
    nine = create_node(9);


    add_left_node(head, seven);
    add_right_node(head, nine);


    one = create_node(1);
    six = create_node(6);
    add_left_node(seven, one);
    add_right_node(seven, six);

    five = create_node(5);
    ten = create_node(10);
    add_left_node(six, five);
    add_right_node(six, ten);


    eight = create_node(8);
    add_right_node(nine, eight);

    three = create_node(3);
    four = create_node(4);

    add_left_node(eight, three);
    add_right_node(eight, four);


    return head;
}


void add_left_node(Node *root, Node *node)
{
    root->left_node = node;
}


void add_right_node(Node *root, Node *node)
{
    root->right_node = node;
}


void print_pre_order(Node *head)
{
    cout << head->data << "  ";

    if(head->left_node != NULL)
        print_pre_order(head->left_node);
    if(head->right_node != NULL)
        print_pre_order(head->right_node);
}


void print_in_order(Node *head)
{
    if(head->left_node != NULL)
        print_in_order(head->left_node);
    
    cout << head->data << "  ";

    if(head->right_node != NULL)
        print_in_order(head->right_node);
}


void print_post_order(Node *head)
{
    if(head->left_node != NULL)
        print_post_order(head->left_node);
    if(head->right_node != NULL)
        print_post_order(head->right_node);
    
    cout << head->data << "  ";
}
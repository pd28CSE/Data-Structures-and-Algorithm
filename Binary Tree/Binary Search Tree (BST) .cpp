#include<iostream>

using namespace std;


typedef struct node Node;
struct node
{
    int data;
    Node *left_node, *right_node;
};


Node* create_node(int data);
void insert_binary_search_tree(Node *head, int data);
Node* find_root_node(Node *head, int data);
void add_left_node(Node *root, Node *new_node);
void add_right_node(Node *root, Node *new_node);
void print_pre_order_tree(Node *head);
void print_in_order_tree(Node *head);
void print_post_order_tree(Node *head);


int main()
{
    Node *head;

    head = create_node(10);
    insert_binary_search_tree(head, 5);
    insert_binary_search_tree(head, 17);
    insert_binary_search_tree(head, 3);
    insert_binary_search_tree(head, 7);
    insert_binary_search_tree(head, 1);
    insert_binary_search_tree(head, 4);
    insert_binary_search_tree(head, 12);
    insert_binary_search_tree(head, 19);
    insert_binary_search_tree(head, 13);

    print_pre_order_tree(head);
    cout << endl << endl;
    print_in_order_tree(head);
    cout << endl << endl;
    print_post_order_tree(head);


    return 0;
}


Node* create_node(int data)
{
    Node *new_node;

    new_node = new Node;
    if(!new_node){
        cout << "Error" << endl;
        return NULL;
    }
    new_node->data = data;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}


void insert_binary_search_tree(Node *head, int data)
{
    Node *new_node, *root_node;

    new_node = create_node(data);
    root_node = find_root_node(head, data);
    
    if(data < root_node->data ) 
        add_left_node(root_node, new_node);
    else if(root_node->data < data)
        add_right_node(root_node, new_node);
}


Node* find_root_node(Node *head, int data)
{
    Node *root_node = NULL;

    while(head != NULL){
        root_node = head;
        if(data < head->data)
            head = head->left_node;
        else if(head->data < data)
            head = head->right_node;
    }

    return root_node;
} 


void add_left_node(Node *root, Node *new_node)
{
    root->left_node = new_node;
    
}


void add_right_node(Node *root, Node *new_node)
{
    root->right_node = new_node;

}


void print_pre_order_tree(Node *head)
{
    cout << head->data << "  ";

    if(head->left_node != NULL)
        print_pre_order_tree(head->left_node);
    if(head->right_node != NULL)
        print_pre_order_tree(head->right_node);
}

void print_in_order_tree(Node *head)
{
    if(head->left_node != NULL)
        print_in_order_tree(head->left_node);
    
    cout << head->data << "  ";

    if(head->right_node != NULL)
        print_in_order_tree(head->right_node);
}

void print_post_order_tree(Node *head)
{

    if(head->left_node != NULL)
        print_post_order_tree(head->left_node);
    if(head->right_node != NULL)
        print_post_order_tree(head->right_node);

    cout << head->data << "  ";
}
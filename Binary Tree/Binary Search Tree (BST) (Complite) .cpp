#include<iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *left, *right, *parent;
};




Node* create_bst();
Node* create_node(int data);
Node* append_node(Node *root, Node *new_node);
Node* search_last_node(Node *root, int data);
void add_left_child(Node *root, Node *new_node);
void add_right_child(Node *root, Node *new_node);
void pre_order(Node *root);
void in_order(Node *root);
Node* Find_node(Node *root, int data);
Node* delete_bst(Node *root, Node *node);
Node* bst_transplant(Node *root, Node *node, Node *new_node);
Node* find_smallest_node(Node *root);


int main()
{
    Node *root, *node;
    int x;

    root = create_bst();
    pre_order(root);
    cout << endl ;
    in_order(root);
    cout << endl << endl;

    cout << "Enter a Number, Which Number You Want to Delete : ";
    cin >> x;

    node = Find_node(root, x);
    if(node != NULL){
        cout << node->data << endl << endl;
        root = delete_bst(root, node);
        pre_order(root);
        cout << endl ;
        in_order(root);
        cout << endl << endl;
    }
    else
        cout << x << " Not Found." << endl;







    return 0;
}

Node* create_bst()
{
    int ara[] = {30, 45, 65, 25, 36, 95, 45, 5, 85, 4, 8, 10};
    int i,n;
    Node *root, *current_node, *last_node;

    n = sizeof(ara)/sizeof(ara[0]);
    root = create_node(40);

    for(i=0; i<n; i++){
        root = append_node(root, create_node(ara[i]));
    }


    return root;
}


Node* create_node(int data)
{
    Node *new_node;

    new_node = new Node;

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    return new_node;
}


Node* append_node(Node *root, Node *new_node)
{
    Node *last_node;

    last_node = search_last_node(root, new_node->data);

    if(new_node->data <= last_node->data){
        add_left_child(last_node, new_node);
       // cout << "Parent : " << last_node->data << "      Add L : " << new_node->data << endl;
    }
    else if(last_node->data < new_node->data){
        add_right_child(last_node, new_node);
       // cout << "Parent : " << last_node->data << "      Add R : " << new_node->data << endl;
    }

    return root;
}


Node* search_last_node(Node *root, int data)
{
    Node *current_node, *pre_node;

    current_node = pre_node = root;
    while(current_node != NULL){
        pre_node = current_node;
        if(data <= current_node->data)
            current_node = current_node->left;
        else
            current_node = current_node->right;
    }

    return pre_node;
}


void add_left_child(Node *root, Node *new_node)
{
    root->left = new_node;
    if(new_node != NULL)
        new_node->parent = root;
}


void add_right_child(Node *root, Node *new_node)
{
    root->right = new_node;
    if(new_node != NULL)
        new_node->parent = root;
}

void pre_order(Node *root)
{
    cout << root->data << "   ";
    if(root->left != NULL)
        pre_order(root->left);
    if(root->right != NULL)
        pre_order(root->right);
}


void in_order(Node *root)
{
    if(root->left != NULL)
        in_order(root->left);
    cout << root->data << "   ";
    if(root->right != NULL)
        in_order(root->right);
}


Node* Find_node(Node *root, int data)
{
    Node *node;

    node = root;
    while(node != NULL){
        if(node->data == data)
            return node;
        else if(data < node->data)
            node = node->left;
        else if(node->data < data)
            node = node->right;
    }

    return NULL;
}


Node* delete_bst(Node *root, Node *node)
{
    Node *mini_node;


    if(node->left == NULL)
        root = bst_transplant(root, node, node->right);
    else if(node->right == NULL)
        root = bst_transplant(root, node, node->left);
    else{
        mini_node = find_smallest_node(node->right);
        if(mini_node->parent != node){
            root = bst_transplant(root, mini_node, mini_node->right);
            add_right_child(mini_node, node->right);
        }
        root = bst_transplant(root, node, mini_node);
        add_left_child(mini_node, node->left);
    }

    delete node;

    return root;
}


Node* bst_transplant(Node *root, Node *node, Node *new_node)
{
    if(root == node)
        root = new_node;
    else if(node->parent->right == node)
        add_right_child(node->parent, new_node);
    else if(node->parent->left == node)
        add_left_child(node->parent, new_node);


    return root;
}


Node* find_smallest_node(Node *root)
{
    Node *mini_node = root;

    while(root != NULL){
        mini_node = root;
        root = root->left;
    }

    return mini_node;
}

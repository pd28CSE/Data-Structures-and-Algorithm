#include<iostream>

using namespace std;


void build_max_heap(int *ara, int n);
void max_heapify(int *ara, int array_length, int parent_node_index);
bool is_max_heap(int ara[], int n);
int parent(int n);
int left_child(int n);
int right_child(int n);
void check_max_heap_or_not(int *ara, int length);
void print_heap(int *ara, int n);
void heap_sort(int *ara, int n);



int main()
{
    bool check;
    int n, i;
   // int ara[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};   // max heap
   // int ara[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 4};  // not max heap
  //  int ara[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};  // not max heap
      int ara[] = {0, 12, 7, 1, 3, 10, 17, 19, 2, 20};  // not max heap
 //  int ara[] = {0, 19,10,17,5,7,12,1,2,3};


    n = sizeof(ara)/sizeof(ara[0]);
    cout << "Array Length : " << n << endl;

    check_max_heap_or_not(ara, n-1);

    cout << "Before Change : " << endl;
    print_heap(ara, n);
    build_max_heap(ara, n-1);
    cout << "After Change : " << endl;
    print_heap(ara, n);

    check_max_heap_or_not(ara, n-1);

    heap_sort(ara, n-1);  /// heap sort

    cout << endl << "After Heap Sort : " << endl;
    print_heap(ara, n);


    return 0;
}

void heap_sort(int *ara, int n)
{
    int i, temp;

    for(i=n; i>1; i--){
        temp = ara[1];
        ara[1] = ara[i];
        ara[i] = temp;
        n -= 1;
        max_heapify(ara, n, 1);
    }
}


void build_max_heap(int *ara, int n)
{
    int i;

    cout << "  Inside build_max_heap."  << endl;
    for(i=n/2; i>=1; i--){
        max_heapify(ara, n, i);
        cout << "Root Index : " << i << endl;
    }
    cout << endl;
}


void max_heapify(int *ara, int array_length, int parent_node_index)
{
    int left_node_index, right_node_index;
    int max_value, temp;

    left_node_index = left_child(parent_node_index);
    right_node_index = right_child(parent_node_index);

    if(left_node_index <= array_length && ara[left_node_index] > ara[parent_node_index])
        max_value = left_node_index;
    else
        max_value = parent_node_index;

    if(right_node_index <= array_length && ara[right_node_index] > ara[max_value])
        max_value = right_node_index;

    if(parent_node_index != max_value){
        temp = ara[parent_node_index];
        ara[parent_node_index] = ara[max_value];
        ara[max_value] = temp;

        max_heapify(ara, array_length, max_value);
    }

    return;
}


bool is_max_heap(int ara[], int n)
{
    int i, j, l, p;

    for(i=n; i>1; i--){
        p = parent(i);
      //  cout << "Parent : " << ara[p] << "    Child : " << ara[i] << endl;
        if(ara[p] < ara[i])
            return false;
    }


    return true;
}


int parent(int n)
{
    return n/2;
}


int left_child(int n)
{
    return n*2;
}


int right_child(int n)
{
    return ((n*2)+1);
}


void check_max_heap_or_not(int *ara, int length)
{
    bool check;

    check = is_max_heap(ara, length);

    cout << endl;
    if(true == check)
        cout << "This is Max Heap." << endl << endl;
    else
        cout << "This is not Max Heap." << endl << endl;
}


void print_heap(int *ara, int n)
{
    int i;
    for(i=1; i<n; i++)
        cout << ara[i] << "  ";
    cout << endl << endl;

    return;
}

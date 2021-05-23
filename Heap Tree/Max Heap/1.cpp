#include<iostream>
#include<cmath>

using namespace std;


void print_ara(int *ara, int n);
int find_parent_node_index(int index);
void check_max_heap_or_not(int *ara, int total_len);
bool Is_max_heap(int *ara, int n);
void buld_max_heap(int *ara, int total_leng);
void max_heapy(int *ara, int total_leng, int root_index);
int find_left_node_index(int root_index);
int find_right_node_index(int root_index);
void heap_sort(int *ara, int total_len);


int main()
{
    int ara[] = {0,1,50,-44,60,59, -45,8,7,5,11, 15};
//    int ara[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};        // Already Max Heap
    int n;

    n = sizeof(ara)/sizeof(ara[0]);

    cout << "Before Change" << endl;
    print_ara(ara, n);

    check_max_heap_or_not(ara, n);

    buld_max_heap(ara, n);

    cout << "After (Build MaxHeap)Change" << endl;
    check_max_heap_or_not(ara, n);
    print_ara(ara, n);

    heap_sort(ara, n);
    cout << "After Heap Sort" << endl;
    print_ara(ara, n);



    return 0;
}


void heap_sort(int *ara, int total_len)
{
    int i, temp;

    for(i=total_len-1; i > 0; i--){
        temp = ara[1];
        ara[1] = ara[i];
        ara[i] = temp;
        max_heapy(ara, i, 1);
    }
}


void buld_max_heap(int *ara, int total_leng)
{
    int i;

    for(i=total_leng/2; i > 0; i--)
        max_heapy(ara, total_leng, i);
}


void max_heapy(int *ara, int total_leng, int root_index)
{
    int left_node_index, right_node_index;
    int max_value_index, parent_index, temp;

    parent_index = root_index;
    left_node_index = find_left_node_index(parent_index);
    right_node_index = find_right_node_index(parent_index);

    if(left_node_index < total_leng && ara[parent_index] < ara[left_node_index])
        max_value_index = left_node_index;
    else
        max_value_index = parent_index;
    if(right_node_index < total_leng && ara[max_value_index] < ara[right_node_index])
        max_value_index = right_node_index;

    if(max_value_index != parent_index){
        temp = ara[parent_index];
        ara[parent_index] = ara[max_value_index];
        ara[max_value_index] = temp;

        max_heapy(ara, total_leng, max_value_index);
    }
}


void check_max_heap_or_not(int *ara, int total_len)
{
    if(Is_max_heap(ara, total_len) == true)
        cout << "Max Heap" << endl;
    else
        cout << "Not Max Heap" << endl;
    cout << endl;
}


bool Is_max_heap(int *ara, int n)
{
    int i, parent_index;

    for(i=n-1; i > 1; i--){
        parent_index = find_parent_node_index(i);

        if(ara[parent_index] < ara[i])
            return false;
    }

    return true;
}


int find_parent_node_index(int index)
{
    return floor(index/2);
}


int find_left_node_index(int root_index)
{
    return (2*root_index);
}



int find_right_node_index(int root_index)
{
    return (2*root_index) + 1;
}



void print_ara(int *ara, int n)
{
    int i;

    for(i=0; i<n; i++)
        cout << ara[i] << "  ";
    cout << endl << endl;
}

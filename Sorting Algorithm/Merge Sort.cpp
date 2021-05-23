#include<iostream>

using namespace std;


void print_ara(int *ara, int n);
void merge_sort(int *ara, int left, int right);
void Merge(int *ara, int left, int mid, int right);

int main()
{
   // int ara[] = {9,8,7,6,5,4,3,2,1,0};
    int ara[] = {95,588,735,66,5,-4,3,52,10,20};
  //  int ara[] = {1,2,3,4,5,6,7,8,9};
    int i, n;


    n = sizeof(ara)/sizeof(ara[0]);
    cout << "Before Change : " << endl;
    print_ara(ara, n);

    merge_sort(ara, 0, n-1);

    cout << "After Change : " << endl;
    print_ara(ara, n);


    return 0;
}



void merge_sort(int *ara, int left, int right)
{
    int mid;

    if(left == right)
        return;

    mid = left + (right - left)/2;

    merge_sort(ara, left, mid);
    merge_sort(ara, mid+1, right);


    Merge(ara, left, mid, right);

    return;
}

void Merge(int *ara, int left, int mid, int right)
{
    int i, left_ara_size, right_ara_size;
    int ara_index, left_ara_index, right_ara_index;


    left_ara_size = mid - left + 1;
    right_ara_size = right - mid;

    int left_ara[left_ara_size], right_ara[right_ara_size];



    for(i=0; i<left_ara_size; i++)
        left_ara[i] = ara[left+i];

    for(i=0; i<right_ara_size; i++)
        right_ara[i] = ara[mid+1+i];


    for(left_ara_index=0,right_ara_index=0,ara_index=left; left_ara_index<left_ara_size && right_ara_index<right_ara_size; ara_index++){
        if(left_ara[left_ara_index] > right_ara[right_ara_index]){
            ara[ara_index] = right_ara[right_ara_index];
            right_ara_index++;
        }

        else{
            ara[ara_index] = left_ara[left_ara_index];
            left_ara_index++;
        }
    }


    while(left_ara_index < left_ara_size){
        ara[ara_index] = left_ara[left_ara_index];
        ara_index++;
        left_ara_index++;
    }

    while(right_ara_index < right_ara_size){
        ara[ara_index] = right_ara[right_ara_index];
        ara_index++;
        right_ara_index++;
    }


    return;
}


void print_ara(int *ara, int n)
{
    int i;

    for(i=0; i<n; i++)
        cout << ara[i] << "  ";

    cout << endl << endl;

    return;
}

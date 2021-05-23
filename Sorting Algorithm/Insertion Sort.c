#include<stdio.h>

void Insertion_Sort(int *ara, int length);

int main()
{
    int ara[] = {5000, 110, 6, 4, 9, 10, 0, 7, 55, -900, 455, 2, 8, 1, 3, 45, 85, 7, -15, 50, -100, 200};
   // int ara[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i, length;

    length = sizeof(ara)/sizeof(ara[0]);

    Insertion_Sort(ara, length);      /// 


    for(i=0; i<length; i++)
        printf("%d  ", ara[i]);



    return 0;
}

void Insertion_Sort(int *ara, int length)
{
    int i, index, data;

    for(i=1; i<length; i++){
        data = ara[i];
        index = i - 1;
        
        while((index >= 0) && (ara[index] > data)){
            ara[index+1] = ara[index];
            index--;
        }
        ara[index+1] = data;
    }
}
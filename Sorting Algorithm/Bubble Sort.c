#include<stdio.h>

void Bubble_sort(int *ara, int length);

int main()
{
    int ara[] = {5, 6, 4, 9, 10, 0, 7, 500, -900, 455, 2, 8, 1, 3, 45, 85, -15, 50, -100, 200};
    int length, i;

    length = sizeof(ara)/sizeof(ara[0]);

    Bubble_sort(ara, length);

    for(i=0; i<length; i++)
        printf("%d  ", ara[i]);


    return 0;
}

void Bubble_sort(int *ara, int length)
{
    int i, j, temp;


    for(i=0; i<length-1; i++){
        for(j=0; j<(length-i-1); j++){
            if(ara[j] > ara[j+1]){
                temp = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = temp;
            }
        }
    }
}
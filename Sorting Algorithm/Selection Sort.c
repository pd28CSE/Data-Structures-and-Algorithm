#include<stdio.h>

void Selection_Sort(int ara[], int length);

int main()
{
    int ara[] = {11, 6, 4, 9, 10, 0, 7, 55, -900, 455, 2, 8, 1, 3, 45, 85, 7, -15, 50, -100, 200};
    int i, length;


    length = sizeof(ara)/sizeof(ara[0]);

    Selection_Sort(ara, length);           ///

    for(i=0; i<length; i++)
        printf("%d  ", ara[i]);

    return 0;
}

void Selection_Sort(int ara[], int length)
{
    int i, j, index, temp;

    for(i=0; i<length-1; i++){
        index = i;
        for(j=i+1; j<length; j++){
            if(ara[index] > ara[j])
                index = j;
        }

        if(index != i){
            temp = ara[index];
            ara[index] = ara[i];
            ara[i] = temp;
        }
    }

}
#include<stdio.h>
#include<stdlib.h>

void Counting_sort(int *ara, int n);

int main()
{
    int n, i, x;
    int ara[50];


    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("%d : ", i+1);
        scanf("%d", &ara[i]);
    }
        
    
    Counting_sort(ara, n);

    for(i=0; i<n; i++)
       printf("%d  ", ara[i]);



    return 0;
}


void Counting_sort(int *ara, int n)
{
    int i, j, k, mx, *Counter, *output;

    mx = ara[0];
    for(i=1; i<n; i++){
        if(ara[i]>mx)
            mx = ara[i];
    }

    Counter = (int*)calloc(sizeof(int), mx+1);
    output = (int*)malloc(sizeof(int)*n);

    if(!Counter || !output){
        printf("Error");
        return ;
    }

    for(i=0; i<=mx; i++)
        Counter[i] = 0;
    
    for(i=0; i<n; i++)
        Counter[ara[i]]++;

    for(i=1; i<=mx; i++)
        Counter[i] += Counter[i-1];


    for(i=n-1; i>=0; i--){
        output[Counter[ara[i]]-1] = ara[i];
        --Counter[ara[i]];
    }
    
    for(i=0; i<n; i++)
        ara[i] = output[i];

}
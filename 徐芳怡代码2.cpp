#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int *arr;
    int N = 0, input=0, i=0;
    int sum = 0, max = 0;
    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int)*N);
    int minus = 0;
 
    for (i = 0; i < N; i++)
    {
        scanf("%d", &input);
        arr[i] = input;
        if (input < 0)
        {
            minus++;
        }
    }
 
    if (minus == N)
    {
        printf("0");
        return 0;
    }
    
    max=arr[1];
    for(i=0;i<N;i++)
    {
        sum=sum+arr[i];
        if (sum>max)
        {
            max=sum;
        }
        if (sum <0)
        {
            sum=0;
        }
    }
    printf("%d",max);
 
    return 0;
 
}

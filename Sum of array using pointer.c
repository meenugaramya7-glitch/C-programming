#include<stdio.h>  //find sum of array using pointer
int main()
{
    int arr[5]={10,20,30,40,50};
    int *p=arr;
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=*(p+i);
    }
    printf("Sum is:%d\n",sum);
    return 0;
}
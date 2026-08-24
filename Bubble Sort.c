#include<stdio.h>  //to implement bubble sort
void bubble_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[6]={10,20,5,9,2,8};
    int i;
    bubble_sort(arr,6);
    for(i=0;i<6;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}

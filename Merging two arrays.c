#include<stdio.h>  //merge two  arrays
int main()
{
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={4,5,6,7,8};
    int arr3[10],i,j;
    //copy arr1 to arr3
    for( i;i<5;i++){
        arr3[i]=arr1[i];
    }
    //copy arr2 to arr3
    for(j=0;j<5;j++)
    {
        arr3[i]=arr2[j];
        i++;
    }
    printf("merged array :");
    for(i=0;i<10;i++)
    {
        printf("%d",arr3[i]);
    }

}
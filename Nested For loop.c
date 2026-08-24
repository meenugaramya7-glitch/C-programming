#include<stdio.h>  //Nested for loop
int main()
{
    for(int i=1;i<=5;i++)
    {
     for(int j=1;j<=5;j++)
     {
        printf("*");
     }
     printf("\n");
    }
    return 0;
}
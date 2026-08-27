#include<stdio.h>  //reverse a string using stack
#include<string.h>
#define MAX 100
int main()
{
    char str[MAX],stack[MAX];
    int top= -1;
    printf("Enter a string:");
    gets(str);
    for(int i=0;str[i]!='\0';i++)
    {
        top++;
        stack[top]=str[i];

    }
    printf("reversed string is: ");
    while(top!=-1)
    {
        printf("%c",stack[top]);
        top--;
    }
    return 0;
}
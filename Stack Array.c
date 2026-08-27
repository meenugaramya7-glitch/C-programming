#include<stdio.h>  //stack array
#define SIZE 5
int stack[SIZE];
int top=-1;
//push operation
void push(int value)
{
    if(top==SIZE-1){
        printf("stack overflow.");
    }
    else{
        top++;
        stack[top]=value;
        printf("%d",value);
    }
}
//pop operation
void pop()
{
    if(top== -1){
        printf("stack underflow.");
    }
    else{
        top--;
        printf("%d",stack[top]);

    }
}
//peek operation
void peek()
{
    if(top==SIZE-1){
        printf("stack underflow.");
    }
    else{
        
        printf("Top element of the stack is: %d",stack[top]);

    }
}
void display()
{
    if(top== -1){
        printf("stack underflow.");
    }
    else{
        
        printf("stack elements are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }

    }
}
int main()
{
    int choice,value;
    while(1){
        printf("\nStack menu----\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.Exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter value:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                 return 0;
                 default:
                 printf("invalid choice\n");


        }
    }
    return 0;
}
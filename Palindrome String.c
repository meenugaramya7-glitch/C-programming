#include<stdio.h>  //palindrome string
#include<string.h>
int main(
    {
        char s[100];
        int i,len,palindrome=1;

        printf("enter a string:\n");
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len/2;i++)
        {
            if(s[i]!=s[len-i-1])
            {
                palindrome=0;
                break;
            }
        }
        if(palindrome)
          printf("palindrome\n");
        else
          printf("not palindrome\n");

    }
    return 0;
)
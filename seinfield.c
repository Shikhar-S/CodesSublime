/*http://www.spoj.com/problems/ANARC09A/*/
#include <stdio.h>
#include <stdlib.h>
char arr[3000];
char pop(int *top)
{
    if(*top==0)
    {
        //printf("Underflow\n");
        return -1;
    }
    else
    {
        *top=*top-1;
        return arr[(*top)];
    }
}
void push(int *top,char value)
{
    if(*top==2000)
    {
        printf("Overflow\n");
    }
    else
    {
        
        arr[*top]=value;
        *top=*top+1;
    }
}
int main(){
    char ch[3000];
    int j=1;
    do{
        int top;
        top=0;
        
        scanf("%s",ch);
        if(ch[0]=='-')break;
        int i=1;
        push(&top,ch[0]);
        while(ch[i]!='\0')
        {
            if(ch[i]=='{')
            {
                push(&top,ch[i]);
            }
            else
            {
                char x=pop(&top);
                if(x!='{')
                {
                    push(&top,x);
                    push(&top,ch[i]);
                }
            }
            i++;
            
        }
        char x=pop(&top);
        int f1=0,f2=0;
        while(x!=-1)
        {
            if(x=='{')
                f1++;
            else
                f2++;
            x=pop(&top);
        }
        int ans=f1/2+f2/2;
        if(f1%2!=0)
        {
            ans+=2;
        }
        
        printf("%d. %d\n",j,ans);
        j++;
    }while(ch[0]!='-');
    
}
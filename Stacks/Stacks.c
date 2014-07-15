#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1,a[MAX];
void push(int item)
{
  if(top<MAX-1)
    a[++top]=item;
  else
    printf("\nStack Full, Please perform Pop operation before Push operation");
}
int pop()
{
  if(top==-1)
  {
    printf("\nStack Empty, Please perform Push operation before Pop operation");
    return -1; //When item entered is -1 returns -1 and recevied function might interpret it as stack empty condition, done just as an example to show seperate usage of the functions also.
  }
  else
    return a[top--];
}
int main()
{
  int ch,num,i=0;
  system("clear");
  do
  {
    printf("\n\nEnter your Choice:\n1>Push Operation\n2>Pop Operation\n3>Display Stack\n4>Exit\nUser Input:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        printf("\nEnter an Element to be pushed into the Stack:");
        scanf("%d",&num);
        push(num);
        break;
      }
      case 2:
      {
        num=pop();
        if(num!=-1)
          printf("\nElement removed from the Stack is :%d",num);
          break;
      }
      case 3:
      {
          printf("\nShows the sequence of Elements Leaving the Stack:\n");
          for(i=top;i>=0;i--)
            printf("\nLocation: %d > Item: %d",i+1,a[i]);
          break;
      }
      case 4:
        exit(0);
      default:
        printf("\nEntered Wrong Input, Please try Again.");
    }
  }while(1);
  return 0;
}

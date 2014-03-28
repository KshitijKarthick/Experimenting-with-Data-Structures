#include<iostream>
#define MAX 10
using namespace std;
struct node
{
    int info;
    struct node *link;
}a[MAX];
typedef struct node *Node;
int main()
{
    int num,ele,i;
    cout<<"\nEnter the Elements to be Entered and Enter -999 to stop:";
    for(i=0;i<MAX;i++)
    {
        a[i].info=-999;
        a[i].link=NULL;
    }
    for(i=0;i<MAX;i++)
    {
        cout<<"\nEnter Element "<<i+1<<":";
        cin>>ele;
        if(ele==-999)
            break;
        num=ele%MAX;
        if(a[num].info==-999)
        {
            Node temp=new struct node;
            temp->info=ele;
            temp->link=NULL;
            a[num].info=0;
            a[num].link=temp;
         }
         else
         {
            Node first=new struct node;
            first=a[num].link;
            while(first->link!=NULL)
                first=first->link;
            Node temp=new struct node;
            temp->info=ele;
            temp->link=NULL;
            first->link=temp;
         }
     }
     int key;
     cout<<"\nEnter Key Element:";
     cin>>key;
     num=key%MAX;
     if(a[num].info==-999)
        cout<<"\nNumber does not exist in the hash table\n";
     else
     {
        int pos=0;
        Node first=new struct node;
        first=a[num].link;
        while(first!=NULL)
        {
            pos++;
            if(first->info==key)
            {
                  cout<<"\nKey found at Row :"<<num<<" position :"<<pos<<"\n";
                  break;
            }
            first=first->link;
        }       
     }
     return 0;
}    

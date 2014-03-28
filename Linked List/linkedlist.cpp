#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *link;
}a[10];
typedef struct node *Node;
int main()
{
    Node first=new struct node;
    first->info=0;
    Node last=new struct node;
    last=first;
    for(int i=0;i<10;i++)
    {
        Node temp=new struct node;
        temp->info=rand()%10;
        temp->link=NULL;
        last->link=temp;
        last=last->link;
    }
    cout<<"\nThe Elements in the Linked List are:\n";
    last=first;
    int i=0;
    while(last->link!=NULL)
    {
        cout<<"\nNode "<<i+1<<": "<<last->info;
        i++;
        last=last->link;
    }
    return 0;
}

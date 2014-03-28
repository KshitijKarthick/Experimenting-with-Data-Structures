#include<iostream>
#include<time.h>
#include<cstdlib>
#include<stdio.h>
#define MAX 10000
#define MAXSIZE 100000
using namespace std;
struct node
{
    int info;
    struct node *link;
}a[MAX];
typedef struct node *Node;
int main()
{
    long int num,ele,i;
    long int lin[MAXSIZE];
    //cout<<"\nEnter the Elements to be Entered and Enter -999 to stop:";
    for(i=0;i<MAX;i++)
    {
        a[i].info=-999;
        a[i].link=NULL;
    }
    for(i=0;i<MAX;i++)
    {
       // cout<<"\nEnter Element "<<i+1<<":";
        //cin>>ele;
        //ele=rand()%MAXSIZE;
        ele=i+1;
        num=ele%MAX;
        lin[i]=ele;
        if(ele==-999)
            break;
         if(i%10000==0)
            cout<<"\nTen Thousandth Case:Element Value :"<<ele<<"\n";    
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
     double duration;
     clock_t start;
     start=clock();
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
     duration=((double)((clock()-start))/CLOCKS_PER_SEC);
     printf("\nTime Taken for Hashing Search Algorithm is:%lf or %g\n",duration,duration);
     start=clock();
     for(i=0;i<MAX;i++)
     {
        if(i%10000==0)
            cout<<"\nTen Thousandth Case\n";
        if(lin[i]==key)
        {
            cout<<"\nElement found at position :"<<i+1<<" Using Linear Search";
            break;
        }
      }      
       duration=((double)((clock()-start))/CLOCKS_PER_SEC);
     printf("\nTime Taken for Linear Search Algorithm is:%lf or %g\n",duration,duration);;
     return 0;
}    

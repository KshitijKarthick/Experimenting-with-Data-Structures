#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
#define MAX 1000
using namespace std;
struct node
{
    struct node *link[26];
    //char info;
};
typedef struct node *Node;
int main()
{
    Node root=new struct node;
    char s[20],ch;
    int i=0,count=0;
    for(i=0;i<26;i++)
        root->link[i]=NULL;
    
    while(true)
    {
        if(count==3)
            break;
        count++;    
        Node temp=new struct node;
        temp=root;
        cout<<"\nEnter a String: and 0 to stop:";
        cin>>s;
        //if(s[i]=='0')
        //    break;
        for(i=0;i<strlen(s);i++)
        {
            ch=toupper(s[i]);
            if(temp->link[ch-65]==NULL)
            {
                Node newnode=new struct node;
                //newnode->info=ch;
                for(i=0;i<26;i++)
                    newnode->link[i]=NULL;
                temp->link[ch-65]=newnode;
                cout<<"\nTest";
            }
            else
                temp=temp->link[ch-65];
         }
         
      }
      cout<<"\nEnter String to be Searched:";
      cin>>s;
      int flag=1;
      for(i=0;i<strlen(s);i++)
      {
         if(flag!=1)
         {
            cout<<"\nString not Found";
            break;
         }
         Node temp=new struct node;
         temp=root;
         ch=toupper(s[i]);
         if(temp->link[ch-65]==NULL)
         {
            flag=0;
            cout<<"\n";
            printf("%c",ch-65);
         }
         else
            temp=temp->link[ch-65];
       }
       return 0; 
}
                
                
            

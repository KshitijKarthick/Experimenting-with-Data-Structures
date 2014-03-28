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
    int i,num,ele,key;
    for(i=0;i<10;i++)
    {
        a[i].info=-999;
        a[i].link=NULL;
    }
    for(i=0;i<10;i++)
    {
        cout<<"\nEnter an Element and -999 to Stop:";
        cin>>ele;
       
        num=ele%10;
        if(a[num].info==-999)
            a[num].info=ele;
        else
        {
            
            Node temp1=new struct node;
            temp1->link=a[num].link; // Debugging here most probably required
            cout<<"Previous Information:"<<temp1->info<<"\n";
            while(temp1->link!=NULL)  
            {
                    cout<<"Traversing through "<<temp1->info<<"\n"; 
                   temp1=temp1->link;   
            }          
            Node temp=new struct node;
            temp->info=ele;
            temp->link=NULL;
            cout<<"Information:"<<temp->info;
            temp1->link=temp;    // Debugging here for attaching
            
        }
    }
    cout<<"\nEnter Key Element :";
    cin>>key;
    num=key%10;
    if(a[num].info==-999)
        cout<<"\nKey does not exist\n";
    else if(a[num].info==key)
        cout<<"\nKey Found at Place a["<<num<<"] in the Hash Table\n";
    else    
    {
        cout<<"Test";
        int pos=0;
        Node temp=new struct node;
        temp->link=a[num].link;
        while(temp->link!=NULL)
        {
            cout<<"Test"<<pos;
            temp=temp->link;
            pos++;
            if(temp->info==key)
            {
                cout<<"\nKey Found at Place a["<<num<<"] in the Position:"<<pos<<"in the Hash Table\n";
                break;
            }
            cout<<"\nKey does not exist\n";
         }
     }
    return 0;
}

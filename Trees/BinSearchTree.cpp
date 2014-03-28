#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *llink,*rlink;
};
typedef struct node *Node;

Node bin_tree()
{
    int num;
    int i,j;
    Node root=new struct node;
    root->llink=root->rlink=NULL;
    Node temp=new struct node;
    temp=root;
    cout<<"\nEnter Root of the tree:";
    cin>>num;
    root->info=num;
    while(num!=-999)
    {
         cout<<"\nEnter Node Value of the tree and -999 to stop input :";
         cin>>num;
         if(num==-999)
            break;
         while(true)
         {   
            if(temp->info>num)
            {
                if(temp->llink==NULL)
                {
                    Node newnode=new struct node;
                    newnode->info=num;
                    newnode->llink=newnode->rlink=NULL;
                    temp->llink=newnode;
                    break;
                }
       
                else
                    temp=temp->llink;
            }
            else
            {
                if(temp->rlink==NULL)
                {
                    Node newnode=new struct node;
                    newnode->info=num;
                    newnode->llink=newnode->rlink=NULL;
                    temp->rlink=newnode;
                    break;
                }
                else
                    temp=temp->rlink;
            }
         }
         temp=root;
      }
      return root;
}
void inorder(Node root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        cout<<"\n"<<root->info;
        inorder(root->rlink);
    }
}
void preorder(Node root)
{
    if(root!=NULL)
    {
        cout<<"\n"<<root->info;
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(Node root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        cout<<"\n"<<root->info;
    }
}
void search(Node root,int num)
{
    while(root!=NULL)
    {
        if(root->info==num)
        {
               cout<<"\nKey Found";   
               return;
        }
        else if(root->info>num&&root->llink!=NULL)
            root=root->llink;
        else if(root->info<num&&root->rlink!=NULL)
            root=root->rlink;
    }
    cout<<"\nKey not Found in the Tree";        
}
int main()
{
      int key;
      system("clear");
      Node root=new struct node;
      root=bin_tree();
      cout<<"\nInorder\n";
      inorder(root);
      cout<<"\n";
      cout<<"\nPreorder\n";
      preorder(root);
      cout<<"\nPostorder\n";
      postorder(root);
      cout<<"\nEnter an element to be searched:";
      cin>>key;
      search(root,key);
      cout<<"\n\n";
      
      return 0;
}

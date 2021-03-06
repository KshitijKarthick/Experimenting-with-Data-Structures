#include<iostream>
#include<cstring>
#include<math.h>
#include<stdio.h>
#define MAX 100
int a[MAX];
using namespace std;
int hash1(char s[],int size)
{
    int len=strlen(s);
    int i;
    int sum=0;
    for(i=0;i<len;i++)
        sum=sum+(s[i]<<(i+1));
    return sum%size;
}
int hash2(char s[],int size)
{
    int len=strlen(s);
    int i;
    long int product=1;
    for(i=0;i<len;i++)
        product=product+(s[i]<<(i+1));

    return product%size;
}
int hash3(char s[],int size)
{
    int len=strlen(s);
    int i;
    int num=1;
    for(i=len-1;i>=0;i--)
        num=int((s[i]>>i)/num);

    return num%size;
}
void save()
{
    char s[20];
    int h1,h2,h3;
    cout<<"\nEnter String to be Saved:";
    cin>>s;
    h1=hash1(s,MAX);
    //cout<<"\nHash 1:"<<h1;
    h2=hash2(s,MAX);
    //cout<<"\nHash 2:"<<h2;
    h3=hash3(s,MAX);
    //cout<<"\nHash 3:"<<h3;
    a[h1]=1;
    a[h2]=1;
    a[h3]=1;
}
void predict()
{
    char s[20];
    int h1,h2,h3;
    cout<<"\nEnter String to be Predicted if Entered:";
    cin>>s;
    h1=hash1(s,MAX);
    //cout<<"\nHash 1:"<<h1;
    h2=hash2(s,MAX);
    //cout<<"\nHash 2:"<<h2;
    h3=hash3(s,MAX);
    //cout<<"\nHash 3:"<<h3;
    if((a[h1]==1&&a[h2]==1)&&a[h3]==1)
        cout<<"\nThe String Exists\n";
    else
        cout<<"\nThe String Does not Exist\n";
}
int main()
{
    int num;
    cout<<"\nEntry of Strings:\n";
   while(true)
    {
        cout<<"\nEnter 1 to Continue anything else to Exit:";
        cin>>num;
        if(num!=1)
            break;
        save();
        fflush(stdin);
   }
   cout<<"\nPRediction of Strings:\n";
    while(true)
   {
       cout<<"\nEnter 1 to Continue anything else to Exit:";
       cin>>num;
       if(num!=1)
           break;
       predict();   
       fflush(stdin);
    }
    return 0;
 }
    

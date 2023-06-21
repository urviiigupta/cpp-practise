#include <iostream>
using namespace std;

void printline(int l,int prevarr[],int n)
{   
    if(l>n)
   { return; }

    int newarr[l];
    newarr[0]=1;
    int i;
    for(i=0;i<l-1;i++)
    {
        newarr[i+1]=prevarr[i]+prevarr[i+1];
    }
    newarr[i]=1;
    for(i=0;i<l;i++)
    {
        cout<<newarr[i]<<" ";
    }
    cout<<endl;
    printline(l+1,newarr,n);

    
}
int main()

{   
    int n;
    cin>>n;
    int arr[2]={1,1};
    if(n>=1)
    {
        cout<<1<<endl;
        
    }
     if(n>=2)
    {

        cout<<"1 1"<<endl;
    }
    if(n>=3)
    {

    printline(3,arr,n); }
    return 0;
}
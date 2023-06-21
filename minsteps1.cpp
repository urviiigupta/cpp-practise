#include <iostream>
#include <limits.h>
using namespace std;

int minsteps(int n,int *arr)
{   if(n==1)
    {
        return arr[n]= 0;
    }
    if(arr[n]!=-1)
    { 
        return arr[n];
    }

    int x,y,z;
    x=y=z=INT_MAX;
   
    x = minsteps(n-1,arr);
    
    if(n%2==0)
    {
        y= minsteps(n/2,arr);
    }

    if(n%3==0)
    {
        z= minsteps(n/3,arr);
    }
    
    return arr[n]=(min(x,min(y,z))+1);
   
 }

 int bottomup(int n)
 {
    int *arr=new int[n+1];
    arr[1]=0;
    
    for(int i=2;i<=n;i++)
    {
        int x,y,z;
        x=y=z=INT_MAX;
        x=arr[i-1];
        if(i%2==0)
        {
            y=arr[i/2];
        }
        if(i%3==0)
        {
            z=arr[i/3];
        }

        arr[i]=min(x,min(y,z))+1;


    }

    return arr[n];
 }



int main()
    {
        int n;
        cin>>n;
        int *arr=new int[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=-1;
        }
        cout<<minsteps(n,arr)<<endl;

        return 0;
    }

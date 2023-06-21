#include <iostream>
using namespace std;

int fibo(int pos)
{
    if(pos==0 || pos==1)
    {
        return pos;
    }
    else
    {
        return fibo(pos-1)+fibo(pos-2);
    }
}
//dp

int dpfibo(int pos,int *arr) //top down 
{
    if(pos==0 || pos==1)
    {
        return arr[pos]=pos;
    }
    else
    {
        if(arr[pos]!=-1)
        {
            return arr[pos];
        }
        return arr[pos]= dpfibo(pos-1,arr)+dpfibo(pos-2,arr);
    }
}

void fibup(int n)
{
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<"  "<<fibo(n);

    //dp 
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    //till now no value is calculated 

    dpfibo(n,arr);
for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
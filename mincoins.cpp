#include <iostream>
#include <limits.h>
using namespace std;

int mincoin(int *deno,int amount, int n)
{   if(amount==0)
    {
        return 0;

    }
    int ans=INT_MAX;

    for(int i=0;i<n;i++)
    {
        int lamount=amount-deno[i];
        if(lamount>=0)
        {
            int a= mincoin(deno,lamount,n);
            if(a!=INT_MAX and a<ans)
            {
                ans=a+1;
            }
        }   
    }
    return ans;
}

int tdmincoin(int *deno,int amount, int n, int *arr)
{   if(amount==0)
    {
        return arr[amount]=0;

    }

    if(arr[amount]!=INT_MAX)
    {
        return arr[amount];
    }
    
    int ans=INT_MAX;

    for(int i=0;i<n;i++)
    {
        int lamount=amount-deno[i];
        if(lamount>=0)
        {
            int a= mincoin(deno,lamount,n);
            if(a!=INT_MAX and a<ans)
            {
                ans=a+1;
            }
        }   
    }  
    
    return arr[amount]=ans;
}

int bottomup(int *deno, int amount, int n)
{
    int *arr=new int[amount+1];
    for(int i=0;i<=amount;i++)
    {
        arr[i]=INT_MAX;
    }

    arr[0]=0;
    for(int curramount=1;curramount<=amount;curramount++)
    {
        for(int j=0;j<n;j++)
        {
            int remain=curramount-deno[j];
            if(remain>=0)
            {
            arr[curramount]=min(arr[remain]+1,arr[curramount]);

            }
        }
    }

    return arr[amount];

}

int main()
{
    int deno[]={1,5,6,9};
    int n=sizeof(deno)/sizeof(int);
    int amount;
    cin>>amount;
    int *arr=new int[amount+1];
    cout<<mincoin(deno,amount,n)<<endl;
    for(int i=0;i<=amount;i++)
    {
        arr[i]=INT_MAX;
    }
    cout<<tdmincoin(deno,amount,n,arr)<<endl;

    cout<<bottomup(deno,amount,n)<<endl;

    return 0;
}
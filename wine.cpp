#include <iostream>
#include <limits.h>
using namespace std;
//2d dp question ----> 2d array 
int maxprofit(int wprice[],int l,int r,int year)
{
    //base case
    {
        if(l>r)
        {
            return 0;
        }
    }

    //rec case
    int op1=year*wprice[l]+maxprofit(wprice,l+1,r,year+1);
    int op2=year*wprice[r]+maxprofit(wprice,l,r-1,year+1);

    return max(op1,op2);
}

int dpmaxprofit(int wprice[],int l,int r,int year,int arr[100][100])
{
    //base case
    {
        if(l>r)
        {
            return arr[l][r]= 0;
        }
    }

    //rec case
    if(arr[l][r]!=0)
    {
        return arr[l][r];
    }
    int op1=year*wprice[l]+dpmaxprofit(wprice,l+1,r,year+1,arr);
    int op2=year*wprice[r]+dpmaxprofit(wprice,l,r-1,year+1,arr);

    return arr[l][r]= max(op1,op2);
}

int btmaxprofit(int wprice[], int el, int er,int n)
{
    int arr[100][100]={0};
    for(int i=0;i<n;i++)
    {
        arr[i][i]=wprice[i]*n;
    }

    
}


int main()
{
    int wprice[]={2,3,5,1,4};
    int n=sizeof(wprice)/sizeof(int);
    int arr[100][100]={0};
    cout<<dpmaxprofit(wprice,0,n-1,1,arr)<<endl;
   cout<<maxprofit(wprice,0,n-1,1)<<endl;

   cout<<btmaxprofit(wprice,0,n-1,n);
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"\t";
        }   
        cout<<endl;
   }

   

    return 0;
}
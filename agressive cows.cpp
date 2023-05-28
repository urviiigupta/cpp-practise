//agressive cows

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int canputcows(int arr[],int n, int cows, int dist)
{
   int  c=arr[0],count=1,i;
   for(i=1;i<n;i++)
   {
       if((arr[i]-c)>=dist)
       {
           count++;
           c=arr[i];
       }
       if(count==cows)
       {
           return 1;
       }
   }
   return 0;
}
int main()
{
    int n;
    cin>>n;
    int cows;
    cin>>cows;
    int i,arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    //least distance can be 1 and highest can be arr[n-1]-arr[0]
    int low=1,result=1;
    int high=arr[n-1]-arr[0];
    while(high>=low)
    {
        int mid=(high+low)/2;
        if(canputcows(arr,n,cows,mid)==1)
        {
            result=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    cout<<"the min distance is "<<result;
    return 0;
}

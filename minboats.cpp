#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{   int n,limit;
    cin>>n;
    cin>>limit;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int boats=0;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(arr[i]+arr[j]<=limit)
        {
            boats++;
            i++;
            j--;

        }
        else{
            boats++;
            j--;
        }
    }
    cout<<"the min boats are "<<boats<<endl;
    return 0;
}

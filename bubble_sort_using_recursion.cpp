//bubble sort using recursion 

#include <iostream>

using namespace std;
void bubblesortrec(int arr[],int n,int i)
{
    if(i==n-1)
   {
       return;
   }
    for(int j=0;j<=n-2-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
    bubblesortrec(arr,n,i+1);
}
int main()
{
    int arr[]={5,4,3,2,1};
    int l=sizeof(arr)/sizeof(int);
    bubblesortrec(arr,l,0);
    int i=0;
    while(i<l)
    {
        cout<<arr[i]<<" ";
        i++;
    }
}

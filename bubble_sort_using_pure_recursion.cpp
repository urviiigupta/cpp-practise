//bubble sort using pure recursion 

#include <iostream>

using namespace std;
void bubblesortrec(int arr[],int n,int i,int j)
{
    if(i==n-1)
   {
       return;
   }
    if(j==n-1-i)
    {   
        bubblesortrec(arr,n,i+1,0);
        return;
        
    }
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
      
    bubblesortrec(arr,n,i,j+1);
}
int main()
{
    int arr[]={5,4,3,2,1};
    int l=sizeof(arr)/sizeof(int);
    bubblesortrec(arr,l,0,0);
    int i=0;
    while(i<l)
    {
        cout<<arr[i]<<" ";
        i++;
    }
}

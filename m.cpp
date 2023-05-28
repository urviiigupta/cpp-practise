#include <iostream>

using namespace std;
void merge(int arr[],int s,int e)
{
    int temp[1000];
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(arr[i]>arr[j])
        {
            temp[k]=arr[j];
            j++;
        }
        else if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++;
        }
        k++;
      
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    k=0;
    while(k<=e)
    {
        arr[k]=temp[k];
        k++;
    }
    
}
void mergesort(int arr[], int s, int e)
{   if(s==e){
    return;
}
    int mid=(s+e)/2;
    
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{ int arr[5]={4,2,1,3,5};
int n=5;
mergesort(arr,0,n-1);
return 0;


    
}

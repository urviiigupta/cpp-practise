//binary using recursion 

#include <iostream>

using namespace std;
int binaryrec(int arr[],int s,int e,int key)
{   if(s>e)
    {
        return -1;
    }
    int mid=(s+e)/2;
    
    if(arr[mid]>key)
    {
       return binaryrec(arr,s,mid-1,key);
    }
    
    else if (arr[mid]==key)
    {
        return mid;
    }
    else 
    {
        return binaryrec(arr,mid+1,e,key);
    }
}
int main()
{
    int arr[]={3,5,7,8,9};
    int l=sizeof(arr)/sizeof(int);
    int key=11;
    cout<<binaryrec(arr,0,l-1,key);
}


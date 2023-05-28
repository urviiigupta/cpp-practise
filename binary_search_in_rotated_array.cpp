#include <iostream>

using namespace std;
int main()
{
    int arr[]={5,8,9,0,1,3,4};
    int l=sizeof(arr)/sizeof(int);
    int target;
    cin>>target;
    int low=0,high=l-1,mid=(low+high)/2;
    while(high>=mid)
    {   mid=(low+high)/2;
       if(arr[mid]==target)
       {
           cout<<mid;
           break;
       }
       if(arr[low]==target)
       {
           cout<<low;
           break;
       }
       if(arr[high]==target)
       {
           cout<<high;
           break;
       }
       else if(arr[mid]>arr[low])
       {
           if (arr[mid]>target && target>arr[low])
           {
               high=mid-1;
           }
           else
           {
               low=mid+1;
           }
       }
       else
       {
           if(arr[mid]<target && arr[high]>target)
           {
               low=mid+1;
           }
           else
           {
               high=mid-1;
           }
       }
    }

    return 0;
}

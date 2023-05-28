#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0,height,width;
    int i=0,j=n-1;
    while(i<j)
    {   
        if (arr[i]>=arr[j])
        {
            height=arr[j];
            width=j-i;
            if(height*width >ans)
         {   
             ans=height*width;
         }
            j--;
        }
        else
        {
            height=arr[i];
            width=j-i;
            if(height*width >ans)
         {   
             ans=height*width;
         }
            i++;
        }
        
        
    }
    cout<<"the max amount of water is "<<ans<<endl;
    return 0;
}
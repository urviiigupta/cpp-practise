#include <iostream>
using namespace std;
long long int kthroot(long long int n,long long int k, long long int s,long long int e)
{ int ans=-1;
    while(s<=e)
    {
        long long int mid=(s+e)/2;
        if(pow(mid,k)<=n)
        {
            ans=mid;
            s=mid+1;

        }
        else{
            e=mid-1;
        }
    }

    return ans;


}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int n;
        int k;
        cin>>n>>k;
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }

    else{
        kthroot(n,k,0,sqrt(n));
        
    }

    }
    return 0;
}
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

bool mycomp(string s1, string s2)
{
    int l1=s1.length();
    int l2=s2.length();

    if(l1>l2 and s2==s1.substr(0,l2))
    {
        return true;
    }

    else
    {
        return s1<s2;   
    }
    

}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string arr[1000];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n,mycomp);

    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;   
}
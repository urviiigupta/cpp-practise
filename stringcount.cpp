#include <iostream>
#include <string>
using namespace std;

int main()
{   string s;
    cin>>s;
    int len=s.length();
    cout<<len<<endl;
    int arr[26]={0};
    for(int i=0;i<26;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<len;i++)
    { cout<<s[i];
        arr[s[i]-97]++;
    }
    for (int i=0;i<26;i++)
    {
        
        {
            char c=i+97;
            cout<<c<<" "<<arr[i];
        }
    }

    return 0;
}
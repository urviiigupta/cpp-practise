#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

stack<int> st;
for(int i=0;i<n;i++)
{
    if(st.empty()==true || arr[i]>0)
    {
        st.push(arr[i]);
    }
    else
    {
        while(!st.empty() && st.top()>0)
        {
            int temp=arr[i]+st.top();
            if(temp<0)
            {
                st.pop();
                if(st.empty()==true)
                {
                    st.push(arr[i]);
                    break;
                }
            }

            else if(temp==0)
            {
                st.pop();
                
                break;
            }

            else
            {
                break;
            }
        }
    }
}

while(!st.empty())
{
    cout<<st.top()<<" ";
    st.pop();
}

    return 0;
}
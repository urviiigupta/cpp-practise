#include "myheaderfile.h"
int main()
{
    stack<int>s;
    s.push(4);
    s.push(5);
    s.push(9);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
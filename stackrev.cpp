#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack <int> &s, int temp)
{   if (s.empty()==true)
    {
        s.push(temp);
        return;
    }
    int temp2=s.top();
    s.pop();
    insertatbottom(s,temp);
    s.push(temp2);
     
}
void stackrev( stack<int> &s)
{  if(s.empty()==true)
{
    return;
}
    int temp=s.top();
    s.pop();
    stackrev(s);
    insertatbottom(s,temp);
    
}
int main()
{
    stack<int> s;
    s.push(9);
    s.push(6);
    s.push(5);
    s.push(4);
    stackrev(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

return 0;
}
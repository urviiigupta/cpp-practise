#include <iostream>
#include <queue>
using namespace std;

class stack
{
     queue<int> q1;
     queue<int> q2;
     public:

    void  push(int d)
        {
            if(q1.empty()==true && q2.empty()==true)
            {
                q1.push(d);
            }
            else if(q1.empty()!=true && q2.empty()==true)
            {
                q1.push(d);
            }
            else 
            {
                q2.push(d);
            }
        }

    void pop()
     {  if(q1.empty() and q2.empty())
        {
            return;
        }
        if(!q1.empty() and q2.empty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }

        else if(q1.empty() and !q2.empty())
        {
            while (q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }

     }

     int top()
     {
        if(q1.empty() and q2.empty())
        {
            return -1;
        }
        if(!q1.empty() and q2.empty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            int temp=q1.front();
            q1.pop();
            return temp;

        }

        else if(q1.empty() and !q2.empty())
        {
            while (q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            q1.push(q2.front());
            int temp=q2.front();
            q2.pop();
            return temp;
        }
     }

    bool empty()
    {
        return q1.size()==0 and q2.size()==0;
    }
    int size()
    {
        return q1.size()+q2.size();
    }
};

int main()

{
    stack s;
    s.push(3);
    s.push(4);
    s.push(9);
    s.push(2);
    s.pop();
    s.push(40);
    s.pop();
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
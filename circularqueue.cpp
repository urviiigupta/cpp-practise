#include <iostream>
#include <queue>
using namespace std;

class Queue{
    int *arr;
    int cs;
    int ts;
    int s;
    int e;
    public:
    Queue(int size=5)
    {
        arr=new int[size];
        ts=size;
        cs=0;
        s=0;
        e=-1;
    }

    //push
    void push(int d)
    {
        if(cs<ts)
        {
            e=(e+1)%ts;
            arr[e]=d;
            cs++;
        }
        else{
            cout<<"overflow"<<endl;
        }

    }


    //pop
    void pop()
    {
        if(cs>0)
        {
            s=(s+1)%ts;
            cs--;
        }
        else{
            cout<<"underflow"<<endl;
        }
    }



    //empty

    bool empty()
    {
        return cs==0;
    }



    //size
    int size()
    {
        return cs;
    }
    int front()
    {
        return arr[s];
    }

};

int main()
{
    Queue q;
    q.push(5);
    q.push(70);
    q.push(71);
    q.push(73);
    q.push(733);
    q.push(4);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
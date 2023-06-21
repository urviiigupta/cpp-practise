#include <iostream>
#include <queue>

using namespace std;
#define Heap priority_queue<int,vector<int>,greater<int>>
void printheap(Heap h)
{
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;

}
int main()
{
    Heap h;   

        int k;
        cin>>k;

        int count=1;

    int data;

    while(1)
    {
    cin>>data;
    if(data==-1)
    {
        printheap(h);

    }
    else
    {
        if(count<=k)
        {
            h.push(data);
            count++;
        }
        else
        {
            if(data>h.top())
            {
                h.pop();
                h.push(data);
            }
        }
    }
    }

    
}
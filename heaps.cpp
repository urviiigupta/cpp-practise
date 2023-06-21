#include <iostream>
#include <vector>
using namespace std;
class Minheap{

    vector<int> v;

    public :
    Minheap()
    {
        v.push_back(-1);
    }

    void insert(int data) //push
    {
        v.push_back(data);
        int child=v.size()-1;
        while(child!=1)
        {
            int parent=child/2; //for 1 based indexing
            if(v[parent]>v[child])
            {
                swap(v[parent],v[child]);
            }
            child=parent;

        }
    }

 void heapify(int index)
    {
        int li=2*index;
        int ri=2*index +1;
        int minindex=index;

        if(li<=v.size()-1 and v[minindex]>v[li])
        {
            minindex=li;
        }

        if(ri<=v.size()-1 and v[minindex]>v[ri])
        {
            minindex=ri;
        }
        if(minindex !=index)
        {
            swap(v[minindex],v[index]);
            heapify(minindex);
        }


    }

 int top()
 {
    return v[1];
 }

 bool empty()
 {
    return v.size()==1;
 }
 
void deletee()
  {
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    heapify(1);
     
  }  
    
};

int main()
{
    Minheap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(17);
    h.insert(19);
    h.insert(36);
    h.insert(7);
    h.insert(25);
    h.insert(100);

    h.insert(0);

    h.deletee();
    cout<<h.top()<<" ";

     h.deletee();
    cout<<h.top()<<" ";

     h.deletee();
    cout<<h.top()<<" ";


    return 0;
}

#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }

} ;

class stack
{   node *head;
    int l;
    public:
    stack()
    {
        head=NULL;
        l=0;
    }
   void push(int d)
   {
    node *n=new node(d);
    n->next=head;
    head=n;
    l++;
   } 
   void pop()
   
        
    {// if it's empty 
        if(head==NULL)
        {
            return;
        }
        //if it has one node 
        else if(head->next==NULL)
        {   delete head;
            head=NULL;
        
            
        }
        else{
        //has multiple nodes
        node *temp=head->next;
        delete head;
        head=temp;
        }
        l--;
    }
    int top()
    {
        return head->data;
    }
    bool empty()
    {
        if(l==0)
        {
            return true;
        }
        return false;
    }
   
};
int main()
{ stack s;
s.push(3);
s.push(4);
while(!s.empty())
{
    cout<<s.top()<<" ";
    s.pop();
}
    return 0;
}
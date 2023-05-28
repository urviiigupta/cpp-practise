//linked list 
#include <iostream>

using namespace std;
//self referencial class
class node{
    public:
    int data;
    node *next; //because we want to store something of node type

    node(int d){
        data=d;
        next=NULL;
    }
};
int main()
{
    node x(9);
    node y(3);
    x.next=&y;
    cout<<x.data;
    cout<<(*x.next).data;
    return 0;
}

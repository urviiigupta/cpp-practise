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
    }};
    void insertatfront(node*&head,node*&tail,int d)
    {
        //case 1 can be empty 
        if (head==NULL and tail==NULL)
        {
            //we will not create object statically 
            node*ptr=new node(d);
            head=ptr;
            tail=ptr;
        }
        else
        {   node *ptr=new node(d);
            ptr->next=head;
            head=ptr;
            
        }
    }
    void insertattail(node*&head,node*&tail,int d)
    {
        //if ll is empty
        if(head==NULL)
        {
            node*ptr=new node(d);
            head=ptr;
            tail=ptr;
            
        }
        else
        {
            node*ptr=new node(d);
            tail->next=ptr;
            tail=ptr;
        }
    }
    void printll(node *head)
    {
        node*temp=head;
        while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
        }
        cout<<endl;
    }
   void deleteatfront(node*&head,node*&tail)
    {// if it's empty 
        if(head==NULL)
        {
            return;
        }
        //if it has one node 
        else if(head->next==NULL)
        {   delete head;
            head=NULL;
            tail=NULL;
            
        }
        else{
        //has multiple nodes
        node *temp=head->next;
        delete head;
        head=temp;
        }
    }

int main()
{
    node *head=NULL;
    node *tail=NULL;
    insertatfront(head,tail,2);
    insertatfront(head,tail,3);
    insertatfront(head,tail,9);
    insertatfront(head,tail,6);
    
    insertattail(head,tail,18);
    printll(head);
    deleteatfront(head,tail);
    printll(head);
    return 0;
}

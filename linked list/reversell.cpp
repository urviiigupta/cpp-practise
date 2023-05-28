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
    
    int lengthofll(node *head)
{
    int l=0;
    node *temp=head;
    while(temp!=NULL)
    {   temp=temp->next;
        l++;
    }
    return l;
}

node* midpointll(node *head) //for even 1st
{
    node*slow=head;
    node *fast=head->next;
    
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
  
    void deleteattail(node *&head,node *&tail)
    {
        if(head==NULL)
        {
            return;
        }
        else if (head->next ==NULL)
        {   delete tail;
            head=NULL;
            tail=NULL;
        }
        else
        {
            node *temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
        }
    }
 
node *reverseofll(node*head)
{
  node *prev=NULL;
  node *current=head;
  while(current !=NULL)
  {
    node *ne=current->next;
    current->next=prev;
    prev=current;
    current=ne;
  }
  return prev;

}


int main()
{
    node *head1=NULL;
    node *tail1=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        insertattail(head1,tail1,d);
    }
    printll(reverseofll(head1));
   
    return 0;
}


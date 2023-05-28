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

/* int midpointll(node *head) //for odd only
{
    node*slow=head;
    node *fast=head;
    
    while(fast->next !=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
} */

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
bool searchinll(node *head,int key)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
    temp=temp->next;
    }
    return false;
}

int kthnodefromend(node *head,int k)
{
    node* p1=head;
    node *p2=head;
    for(int i=1;i<=k;i++)
    {
        p2=p2->next;
    }
    while(p2!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1->data;
    
    
}
node* mergeintoone(node *head1,node *head2)
{
    //llempty 
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
   if(head1->data < head2->data)
   {
       node *newhead=head1;
       
       newhead->next=mergeintoone(head1->next,head2);
       return newhead;
   }
   else
   {
       node *newhead=head2;
       
       newhead->next=mergeintoone(head1,head2->next);
       return newhead;
   }
   
   
}

node *mergesort(node*head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //rec case
    // 1st find mid
    node *m=midpointll(head);
    node *temp=m->next;
    m->next=NULL;
    node *x=mergesort(head);
    node *y=mergesort(temp);
    return mergeintoone(x,y);
    
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
   node * nhead=mergesort(head1);
   printll(nhead);
   
    return 0;
}


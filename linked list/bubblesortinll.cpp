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

int midpointll(node *head) //for even 1st
{
    node*slow=head;
    node *fast=head->next;
    
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
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

void bubblesort(node *head,node *tail)
{
   for(int i=0;i<lengthofll(head)-1;i++)
   {
       for(node *j=head;j!=tail;j=j->next)
       {
           if(j->data>j->next->data)
           {
               swap(j->data,j->next->data);
           }
       }
   }
}

int main()
{
    node *head=NULL;
    node *tail=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        insertattail(head,tail,d);
    }
    bubblesort(head,tail);
    printll(head);
    return 0;
}

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
    
void deleteatanypos(node *&head,node *&tail,int pos)
{
    if(pos==0)
    {
        deleteatfront(head,tail);
    }
    else if(pos>=lengthofll(head)-1)
    {
        deleteattail(head,tail);
    }
    else
    {
        node*temp=head;
        for(int jump=1;jump<=pos-1;jump++)
        {
            temp=temp->next;
        }
        node *ptr=temp->next; 
        temp->next=ptr->next;
        delete ptr;
        ptr=NULL;
    }
}


void insertatpos(node *&head,node *&tail,int d, int pos)
{
    node *temp=head;
    if(pos==0)
    {
        insertatfront(head,tail,d);
    }
    else if(pos>=lengthofll(head))
    {
        insertattail(head,tail,d);
    }
    else
    {
        node *temp=head;
        for(int jump=1;jump<=pos-1;jump++)
        {
            temp=temp->next;
        }
        node *ptr=new node(d);
        ptr->next=temp->next;
        temp->next=ptr;
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
     printll(head);
    insertattail(head,tail,18);
     printll(head);
    //deleteatfront(head,tail);
    insertatpos(head,tail,5,3);
     printll(head);
    deleteattail(head,tail);
    printll(head);
    return 0;
}

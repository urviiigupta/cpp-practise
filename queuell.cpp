 #include <iostream>
 using namespace std;

 class node{
   public:
   int data;
   node *next;
   node(int d)
   {
      data=d;
      next=NULL;
   }
 };
class queue{
   node*head;
   node*tail;
   int len;
   public:
   queue()
   {
      head=NULL;
      tail=NULL;
   
   }
   
   //push
  void  push(int d)
   {
       
        //if ll is empty
        if(head==NULL)
        {
            node*ptr=new node(d);
            head=ptr;
            tail=ptr;
            len++;
            
        }
        else
        {
            node*ptr=new node(d);
            tail->next=ptr;
            tail=ptr;
            len++;
        }
    }
   

   //pop
   void pop()
   {
       if(head==NULL)
        {
            return;
        }
        //if it has one node 
        else if(head->next==NULL)
        {   delete head;
            head=NULL;
            tail=NULL;
            len--;
            
        }
        else{
        //has multiple nodes
        node *temp=head->next;
        delete head;
        head=temp;
        len--;
        }
   }

   //front 
   int front()
   {
      return head->data;
   }

   int size()
   {
      return len;
   }
   bool empty()
   {
      return len==0;
   }
};
 int main()
{  queue q;
   q.push(5);
   q.push(3);
   q.push(44);
   q.push(9);
   
   while(!q.empty())
   {
      cout<<q.front()<<" ";
      q.pop();
   }
   
    return 0;
 }
#include <iostream>
#include <queue>
#include<limits.h>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node(int d)
{
    data =d;
    left=NULL;
    right=NULL;
}
};

class linkl{
    public:
    node *head;
    node *tail;
    linkl()
    {
        head=NULL;
        tail=NULL;
    }
    

};
void levelwise(node *root)
{
    queue <node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
    node *x=q.front();
    q.pop();
    if(x==NULL)
    {
        cout<<endl;
        if (!q.empty())
        {
            q.push(NULL);
        }
    }
    else
    {
        cout<<x->data<<" ";
    

    if(x->left!=NULL)
    {
        q.push(x->left);
    }
    if(x->right!=NULL)
    {
        q.push(x->right);
    }
    }}
}

int heightoftree(node*root)
{   if(root==NULL)
{
    return 0;
}
    return max(heightoftree(root->left),heightoftree(root->right))+1;
}
node *insertinbst(node *root,int data)
{
    if (root==NULL)
    {
        root =new node(data);
        return root;
    }
    else if(data>root->data)
    {
        root->right=insertinbst(root->right,data);
        return root;
    }
    else
    {
        root->left=insertinbst(root->left,data);
        return root;
    }

}
node *buildbst()
{   node *root=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    {
    root=insertinbst(root,data);
    cin>>data;
    }
    return root;


}

bool searchinbst(node *root, int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    else if(root->data>key)
    {
        return searchinbst(root->left,key);
    }
    else{
        return searchinbst(root->right,key);
    }
}

void noinrange(node *root,int k1,int k2)
{
    if(root==NULL)
    {
        return;
    }
    noinrange(root->left,k1,k2);
    if(root->data>=k1 && root->data<=k2)
    {
        cout<<root->data<<" ";
    }
    
    noinrange(root->right,k1,k2);
}

bool checkbst(node*root,int min=INT_MIN, int max=INT_MAX)
{
    if (root==NULL)
    {
        return true;
    }
    if(root->data>=min and root->data<=max and checkbst(root->left,min,root->data)==true and checkbst(root->right,root->data,max)==true)
    {
        return true;
    }
    return false;
}
int arr[]={1,2,3,4,5,6,7,8};
int n=sizeof(arr)/sizeof(int);

node * buildbstarr(int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
   node*root= new node(arr[mid]);
   root->left=buildbstarr(s,mid-1);
   root->right=buildbstarr(mid+1,e);
}

linkl convertbstintoll(node *root)
{    linkl l;
    if(root==NULL)
    {
        return l;
    }
    //neither lst or rst exist 
    if(root->left==NULL and root->right==NULL)
    {
        l.head=root;
        l.tail=root;
        return l;
        
    }

    //only lst and no rst
    else if(root->left !=NULL and root->right==NULL)
    {
        
        linkl le=convertbstintoll(root->left);
        le.tail->left=root;
        root->left=NULL;
        l.head=le.head;
        l.tail=root;
        return l;
    }
    else if (root->right!=NULL and root->left==NULL)
    {
        linkl ri=convertbstintoll(root->right);
        root->left=ri.head;
        l.head=root;
        l.tail=ri.tail;
        return l;
    }
    else
    {
       linkl li= convertbstintoll(root->left);
        linkl ri=convertbstintoll(root->right);

        li.tail->left=root;
        root->left=ri.head;
        l.head=li.head;
        l.tail=ri.tail;
        l.tail->left=NULL;
        return l;

    }
    return l;
}
void printll(node *root)
{   while(root!=NULL)
{
    cout<<root->data<<" ";
    root=root->left;
}
cout<<endl;
}

node * deletioninbst (node *root, int key)
{
    //base case

    //rec case
    //key in lst
    if(key<root->data)
    {   
      root->left=deletioninbst(root->left, key);
      return root;

    }
    //key in rst
    else if(key>root->data)
    {
        root->right=deletioninbst(root->right, key);
      return root;
    }

    //key is at root 
    else
    {
        if(root->left==NULL and root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }

        else if(root->left !=NULL and root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            root=NULL;
            return temp;
        }

        else if(root->right !=NULL and root->left==NULL)
        {
            node *temp=root->right;
            delete root;
            root=NULL;
            return temp;
        }

        else
        {
            // root is max of lst
             node *temp=root->left;
            while(temp!=NULL)
            {
                temp=temp->right;
            }

            swap(root->data, temp->data);
            root->left=deletioninbst(root->left, key);
            return root;
        

        }
    }
}

void rightview(node *root,int cl, int &mlptn ) //1 and 0 start
{
   if(root==NULL)
   {
        return;
   } 
   if(cl>mlptn)
   {
        cout<<root->data<<" ";
        mlptn++;
   }
    rightview(root->right,cl+1,mlptn);
    rightview(root->left,cl+1,mlptn);


}
int main()
{
    node* root=buildbstarr(0,n-1);
    int ml=0;
    rightview(root,1,ml);
    
    return 0;
}
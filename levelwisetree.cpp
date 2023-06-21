#include <iostream>
#include <queue>
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


node * buildtree()
    {
        int d;
        cin>>d;
        if(d==-1)
        {
            return NULL;
        }
        else {
        node *root=new node(d);
        root->left=buildtree();
        root->right=buildtree();
        return root;
        }
    }
node * buildtreelevelwise()
{
    
    node *root=NULL;
    cout<<"enter the data of root "<<endl;
    int data;
    cin>>data;
    queue<node *>q;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
    node *x=q.front();
    q.pop();
    cout<<"enter the left and right children of "<<x->data<<endl;
    int le, ri;
    cin>>le>>ri;
    if(le!=-1)
    {
       x->left= new node(le);
       q.push(x->left);
    }
    if(ri!=-1)
    {
        x->right=new node(ri);
        q.push(x->right);
    }

    }
    return root;
}
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
int main()
{   node* root=buildtreelevelwise();
    levelwise(root);
    return 0;
}
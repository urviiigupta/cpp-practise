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
int preo[]={8,10,1,6,4,7,3,14,13}; //root lst rst
int ino[]={1,10,4,6,7,8,3,13,14};// lst root rst
int i=0;
node * buildtreeusinginpre(int s, int e)
{    if(s>e)
    {
        return NULL;
    }
    int data=preo[i];
    i++;
    node *root=new node(data);
 //iterate in in arr from s to e to find data
    int k;
    for(int j=s;j<=e;j++)
    {
        if(ino[j]==data)
        {
            k=j;
            break;
        }
    }
    root->left=buildtreeusinginpre(s,k-1);
    root->right=buildtreeusinginpre(k+1,e);
    return root;
}

int main()
{   int n=sizeof(preo)/sizeof(int);
    node* root=buildtreeusinginpre(0,n-1);
    levelwise(root);
    return 0;
}
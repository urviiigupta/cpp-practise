#include <iostream>
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
void preorder(node *root)
    {
        if(root==NULL)
        {
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }
void inorder(node *root)
    {
        if(root==NULL )
        {
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }
void postorder(node *root)
    {
        if(root==NULL )
        {
            return;
        }
        postorder(root->left);
        
        postorder(root->right);
        cout<<root->data<<" ";
        
    }

int countnodes(node *root)
{
    //base case 
    if(root==NULL)
    {
        return 0;
    }
    //rec case
    return countnodes(root->left)+countnodes(root->right)+1;
}
bool searchinabt(node *root,int key)
{   if(root==NULL)
    {
        return false;
    }
    if (root->data==key || searchinabt(root->left,key)||searchinabt(root->right,key))
    return true;
    return false;
}
int heightoftree(node*root)
{   if(root==NULL)
{
    return 0;
}
    return max(heightoftree(root->left),heightoftree(root->right))+1;
}

int diameter(node*root) //this for o of n square 
{   if(root==NULL)
    {
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=heightoftree(root->left)+heightoftree(root->left);
    return max(op1,max(op2,op3));
}

class p{
public:
int hei;
int dia;

p()
{
   hei=0;
   dia=0;
}
};

p fastdiameter(node *root)
{   //base case
    
    p n;
    if(root==NULL)
    {
        return n;
    }
    //rec
    p x=fastdiameter(root->left);
    p y=fastdiameter(root->right);
    n.hei=max(x.height,y.height)+1;
    // n ka dia 
    int op1=x.dia;
    int op2=y.dia;
    int op3=x.hei+y.hei;
    n.dia=max(op1,max(op2,op3));
    return n;
}
int main()
{
    //node x(4);
    node*root=buildtree();
    cout<<diameter(root);

   

    return 0;
    }
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
int main()
{
    //node x(4);
    node*root=buildtree();

    cout<<"preorder is  ";
    preorder(root);
    cout<<endl;
    cout<<"inorder is  ";
    inorder(root);
    cout<<endl;
    cout<<"postorder is  ";
    postorder(root);
    cout<<endl;

    cout<<countnodes(root)<<endl;
int key;
cin>>key;
    if(searchinabt(root,key)==true )
    {
        cout<<"key is presnt "<<endl;
    }
cout<<heightoftree(root)<<endl;

    return 0;
    }
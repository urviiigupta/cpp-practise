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

void mirror(node*root)
{   //base case
    if(root==NULL)
    {
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);

}


int main()
{
    //node x(4);
    node*root=buildtree();
    
        mirror(root);
        preorder(root);
   

    return 0;
    }
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

class pai
{ public:
    bool isbal;
    int hei;
    pai()
    {
        isbal=true;
        hei=0;
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
pai  isbalance(node *root)
{   pai l;

    //base case
    {
        if(root==NULL)
        {
            return l;
        }
    }

    //rec case
    pai x=isbalance(root->left);
    pai y=isbalance(root->right);
    l.hei=max(x.hei,y.hei)+1;
    if(x.isbal==true and y.isbal==true and abs(x.hei-y.hei)<=1)
    {
        l.isbal=true;
    }
    else{
    l.isbal=false;
    }
    return l;
}




int main()
{
    node* root=buildbst();
    pai x=isbalance(root);
   if(x.isbal==true)
   {
    cout<<"yayayya"<<endl;
   }
   else
   {
    cout<<"not bal"<<endl;
   }

    return 0;
}
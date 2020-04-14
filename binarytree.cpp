#include<iostream>
using namespace std;
struct node
{
     int data;
     struct node *right;
     struct node *left;
};

struct node *create()
{
    int x;
    struct node *newnode;
    newnode = new node;
    cout<<endl<<"enter the data of the node and  enter -1 for no node ";
    cin>>x;
    if(x == -1)
    {
        return 0;
    }
    newnode -> data = x;
    cout<<endl<<"data for the left node"<<endl;
    newnode -> left = create();
    cout<<endl<<"data for the right node"<<endl;
    newnode -> right = create();
    return newnode;
}
int preorder(struct node *print)
{
    if (print == 0)
    {
        return 0;
    }
    cout<<print -> data<<" ";
    preorder(print -> left);
    preorder(print ->right);

}
int  postorder( node *print)
{
     if (print == 0)
    {
        return 0;
    }
    postorder(print->left);
    postorder(print->right);
    cout<<print->data<<" ";
}
int inorder(node *print)
{
      if (print == 0)
    {
        return 0;
    }
    inorder(print->left);
    cout<<print->data<<" ";
    inorder(print->right);
}

void  dispay()
{

    int u=0,p;
    y:
    cout<<endl<<"select the type of traversal of the tree to be followed: "<<endl<<"1: preorder(Root,left ,right) "<<endl;
    cout<<endl<<"2:postorder travesal(left,right,root) "<<endl<<"3: inorder traversal(left,root,right)"<<endl;
    cin>>u;
    switch(u)
{
    case 1 : preorder(root);
              break;
    case 2 : postorder(root);
                break;
    case 3 : inorder(root);
                break;
    default : cout<<endl<<"This is the wrong choice"<<endl;
    }
    cout<<endl<<"press 0 "<<endl;
    cin>>p;
    if(p == 0)
    {
        goto y;
    }
}

int main()
{
    cout<<endl<<"First we will create a Binary Tree:"<<endl;
    root = 0;
    root = create();
    dispay();
}

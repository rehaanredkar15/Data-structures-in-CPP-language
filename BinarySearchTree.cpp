#include<iostream>
using namespace std;
struct node
{
   int data ;
   struct node *right;
   struct node *left;
};
node *create(int data)
{
    node *newnode = new node;
    newnode ->data = data;
    newnode -> right = 0;
    newnode -> left = 0;
    return newnode;  //here the pointer to the new node is given as the return so that the function caller will receive it

}
node *Insert(node *root,int data)   //here data type used is node * i.e pointer because it  returns pointer at the end
{
   if (root == 0)
   {
       root = create(data); /* if the tree is  empty than a node is created and this condition also acts as stopping condition for
                              recursions to the leftmost and rightmost  node traversal (remember here  the root contains the location of the newnode )
                              in some conditions it  produces the new node and returns  to the calls that invoked it(calls in else if conditions)*/
   }
   else if(data <= root->data)
   {
        root ->left = Insert(root->left,data);//this function call is used to recursively call insert function and reach the leftmost node
                                          //here the left part of the node is used as a parameter
   }
   else
   {
       root -> right = Insert(root->right,data);
   }
  return root;  /*when the insertion is done the root i.e the pointer of the start is returned
                   to the function called (start pointer is returned because the function is  recursive and backtracks)*/
}
int find(node *fin,int s)  //this function whereas returns int value
{
    int g ;
    if(fin == NULL)//this condition is stopping condition
    {
        return NULL;  // this condition returns 0 if the node if not found
    }
    else if (fin->data == s)
    {
        cout<<endl<<"the data is found"<<endl; // if the search is found at the root
        return fin->data;     /*this return depends on the function that
                               called it (it can  main  function if the  node is at root )
                               else it can be one of the function in else if condition*/
    }
    else if(s <= fin->data)
    {
        return find(fin->left,s);  //to move to Left where nodes are smaller
    }
    else
    {
        return  find (fin ->right,s);//to move to right where nodes are bigger
    }
}
int findmin(struct node *root)  /*in this function the root is taken as parameter */
{
    if(root ->left == NULL)    /*until we reach the end we recursive call then function and return the data
                                of node when found*/
    {
        return root->data;

        }
    return findmin(root->left);  //here the recursive call is given to the function
}
node *remove(node *root,int data)
{
    if(root == NULL)
    {
        return root;
    }
    else if(data < root ->data)/* now if the data is smaller than the left recursion is called to reach that node
                               which means this condition works only if the data is smaller */
    {
        root ->left = remove(root->left,data); /*here the root->left is used because after deletion the new address of
                                                node which is the left child is returned as address to the left link */
    }
    else if(data >root->data)/* now if the data is bigger than the right recursion is called to reach that node
                               which means this condition works only if the data is bigger */
    {
        root ->right = remove(root ->right,data);/*here the root->right is used because after deletion the new address of
                                                node which is the right child is returned as address to the right link */
    }
/* we have written the conditions for data to be bigger or smaller , so this else acts as the condition that the
          data to be deleted has found and now  */
    else
  {
    if(root->left == NULL && root ->right == NULL) //if the node doesnt has any sub nodes then we can remove  it and return 0

         {
            delete root;
            root = NULL;
        }
        //below are the nodes with one child
         else if(root -> right == NULL)  /*if the node has only left child then we use a
                                            temporary variable to store that root address and then we move that node to root and we delete that
                                             node using temp to access it so that space is  not wasted*/
         {
             struct node *temp;
             temp =  root;
             root = root -> left;
             delete temp;
         }
         else if(root ->left == NULL)  /* similar like the above process only change  here
                                        is the operations are performed on right node */
         {
              struct node *temp;
             temp =  root;
             root = root -> right;
             delete temp;
         }
            //below are the nodes with 2 child
        else
        {
           int temp = findmin(root->right);//here we receive the smallest no as parameter and save it  in root
            root ->data = temp;
            root -> right = remove(root ->right ,root->data);//and than we call remove function to delete the node so that smaller no takes that place
        }
   }
   return root;
}
int main()
{
    int nod;
    struct node *root = 0;
    //denotes empty tree
    root = Insert(root,15);// here the function is called and received in the root pointer so that root points to  that inserted node now
	root = Insert(root,10);//now the next value goes to the function where it is compared with the existing values
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	cout<<endl<<"now to find any number in the tree"<<endl;
	cout<<endl<<"enter the no to be searched in the tree"<<endl;
    int s=0;
    cin>>s;
	if(find(root,s) == s)  //the function here  returns the no or returns zero if it cannot find the no
    {
        cout<<endl<<"data is FOUND";
    }
    else
    {
        cout<<endl<<"data is not found";
    }
    cout<<endl<<"Now we will delete the given node from the tree"<<endl;
    cout<<endl<<"enter the node to be deleted"<<endl;
    cin>>nod;
    remove(root,nod);
    cout<<endl<<"now lets  us check if the node is deleted or not "<<endl;
    if( find(root,nod) == 0)  //the function here  returns the no or returns zero if it cannot find the no
    {
        cout<<endl<<"data is deleted";
    }
    else
    {
        cout<<endl<<"data is not deleted";
    }
    cout<<endl<<"now let us find the  minimum element in the tree";
    int tato = findmin(root);//here tato receives  the  node and than we print tato
    cout<<endl<<tato;
    return 0;
}

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct  node *prev;
};
struct node* head,*tail;
void create(int n)
{
     node *newnode = new node();
     newnode -> data = n;
     newnode -> next = 0;
     newnode -> prev = 0;
     if(head == 0)
     {
         head = newnode;
         tail = newnode;
     }
     else
      {
           tail -> next = newnode;
         newnode -> prev = tail ;
         tail = newnode;
    }

}
void print()
{
      cout<<endl<<"now we print the list";
     struct node *temp2 = head;
     cout<<endl<<"the list is "<<endl;
     while(temp2 != NULL)
     {
          cout<<" "<<temp2 -> data;
          temp2 = temp2 -> next;
     }
}
void insertbeg()
{
    int a,info;
      cout<<endl<<"enter the info /no at the  node ";
      cin>>info;

    int i;
    struct node *temp = new node();
     temp ->data = info;
     temp ->next = 0;
     temp ->prev = 0;
     head -> prev = temp;
     temp -> next = head;
     head = temp;
}
void insertmid()
{
    int pos;
    struct node *temp2 = head;
  cout<<endl<<"enter the position where you want to insert the node :";
  cin>>pos;
    int i,info;
      cout<<endl<<"enter the info /no at the  node ";
      cin>>info;
      struct node *temp = new node();
      struct node *catch1;
     temp ->data = info;
     temp ->next = 0;
     temp ->prev = 0;

      for(i=0;i<3;i++)
      {
          temp2 = temp2 -> next;
      }
      catch1 = temp2 -> prev;
      catch1 -> next = temp;
      temp2 -> prev = temp;
      temp -> prev = catch1;
      temp -> next = temp2;
}


void del(int pos)
{
     print();
       cout<<endl<<"delete node from the linked list";
      cout<<endl<<"give the position of the node to be removed";
      cin>>pos;

    int i;
    struct node *tempo = head;
     struct node *tempo2 = head;
    if(pos == 1)
    {
     int i;
     for(i=1;i<pos;i++)
     {
         tempo = tempo -> next;
     }
     head =  tempo -> next;
    }
     for(i=1;i<pos;i++)
     {
         tempo = tempo -> next;
     }
         for(i=1;i<pos-1;i++)
     {
         tempo2 = tempo2 -> next;
     }
     tempo2 ->next = tempo->next;
     print();
}
int main()
{
     head = NULL;
     int i,n,a,info,pos,r,y;
     char o;
      cout<<"first we will create a linked list with 3 elements where nos are added at the begining";
           cout<<endl<<"enter the 3 elements to be entered in the list";
      for(i=0;i<3;i++)
      {
           cin>>n;
           create(n);
      }
      r:
      cout<<endl<<"select the function you want to perform"<<endl<< " 1: insert at the begining"<<endl<< "2:insert at a desired position" <<endl<<"3:insert  at end position "<<endl<< " insert at end "<<endl<<"4:print the list "<<endl;
      cout<<endl;
      cin>>y;

      switch(y)
      {
              case 1 :insertbeg();
                         break;
              case 2 :  insertmid();
                       break;
              case 3 : insertend();
                           break;
              case 4 : print();
                         break;
              default : cout<<"wrong choice";
      }
      print();
      cout<<endl<<"do you want to continue performing operations on the list?? if yes then press y otherwise press any key"<<endl;
      cin>>o;
      if (o == 'y')
      {
          goto r;
      }

   return 0;
}

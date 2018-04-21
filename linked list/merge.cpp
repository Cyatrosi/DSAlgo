#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
struct node *next;
};
node * newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
};
node * addnode(node *head,int data)
{
    if(head == NULL)
        return newnode(data);
    head->next = addnode(head->next,data);
    return head;
}
void display(node *head)
{
    if(!head)
        return;
    cout<<head->data<<" ";
    display(head->next);
}
node * mergelist(node *l1,node *l2)
{
    struct node *head = new node();
    if(l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL && l2 != NULL)
    {
        head->data = l2->data;
        head->next = mergelist(l1,l2->next);
    }
    else if(l1 != NULL && l2 == NULL)
    {
        head->data = l1->data;
        head->next = mergelist(l1->next,l2);
    }
    else
    {
        if(l1->data<l2->data)
        {
            head->data = l1->data;
            head->next = mergelist(l1->next,l2);
        }
        else
        {
            head->data = l2->data;
            head->next = mergelist(l1,l2->next);
        }
    }
    return head;
}
int main()
{
struct node *l1 = NULL,*l2 = NULL;
for(int i=0;i<10;++i)
    l1 = addnode(l1,i+1);
for(int i=0;i<10;++i)
    l2 = addnode(l2,i+11);
display(l1);
cout<<endl;
display(l2);
cout<<endl;
struct node *l3 = mergelist(l1,l2);
display(l3);
return 0;
}

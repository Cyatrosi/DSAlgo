// For this question value of N is not known in advance
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
node * k_by_nth(node *head,int k)
{
    if(k<=0)
        return NULL;
    node *ptr = NULL,*temp = head;
    int i=1;
    while(temp!=NULL)
    {
        if(i%k == 0)
        {
            if(ptr == NULL)
                ptr = head;
            else
                ptr = ptr->next;
        }
        ++i;
        temp = temp->next;
    }
    return ptr;
}
int main()
{
node *head = NULL;
for(int i=0;i<10;++i)
    head = addnode(head,i+1);
display(head);
int k = 3;
node *temp = k_by_nth(head,k);
cout<<endl<<temp->data;
return 0;
}

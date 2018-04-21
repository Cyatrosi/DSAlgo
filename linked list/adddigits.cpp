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
struct node *reverselist(struct node *head)
{
if(head == NULL)
    return NULL;
if(head->next == NULL)
    return head;
struct node *revlist = reverselist(head->next);
head->next->next = head;
head->next = NULL;
return revlist;
}
node * add(node *l1,node *l2,int carry)
{
    int sum;
    struct node *head = new node();
    if(l1 == NULL && l2 == NULL)
        {
            if(carry!=0){
                head->data = carry;
                head->next = NULL;
                return head;
            }
            else
            {
                free(head);
                return NULL;
            }
        }
    else if(l1!=NULL && l2 == NULL){
    sum = (l1->data + carry)%10;
    carry = (l1->data + carry)/10;
    head->data = sum;
    head->next = add(l1->next,l2,carry);
    }
    else if(l1==NULL && l2 != NULL){
    sum = (l2->data + carry)%10;
    carry = (l2->data + carry)/10;
    head->data = sum;
    head->next = add(l1,l2->next,carry);
    }
    else
    {
    sum = (l1->data + l2->data + carry)%10;
    carry = (l1->data + l2->data + carry)/10;
    head->data = sum;
    head->next = add(l1->next,l2->next,carry);
    }
    return head;
}
node* addlist(node *l1,node *l2)
{
    int carry = 0;
    struct node *head = add(reverselist(l1),reverselist(l2),carry);
    return reverselist(head);
}
int main()
{
struct node *l1 = NULL,*l2 = NULL;
for(int i=0;i<1;++i)
    l1 = addnode(l1,9);
for(int i=0;i<1;++i)
    l2 = addnode(l2,9);
display(l1);
cout<<endl;
display(l2);
cout<<endl;
struct node *sum = addlist(l1,l2);
display(sum);
return 0;
}

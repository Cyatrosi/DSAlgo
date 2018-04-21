#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node * next;
};
struct node *newlistnode(int key)
{
    struct node *temp = new node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
struct node *addnode(struct node *start,int key)
{
    if(start == NULL)
        return newlistnode(key);
    else
    {
        start->next = addnode(start->next,key);
        return start;
    }
}
void display(struct node *head)
{
    if(head == NULL)
        return;
    cout<<head->key<<" ";
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
};
int main()
{
struct node *head = NULL;
for(int i=0;i<10;++i)
    head = addnode(head,i+1);
display(head);
head = reverselist(head);
cout<<endl;
display(head);
return 0;
}

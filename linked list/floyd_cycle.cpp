#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node * next;
};

struct tnode
{
    int key;
    struct tnode *left,*right;
};
struct node * newnode(int key)
{
    struct node *nn = new node;
    nn->next = NULL;
    nn->key = key;
    return nn;
};
struct node * addnode(struct node *head,int key)
{
    if(head == NULL)
        return newnode(key);
    head->next = addnode(head->next,key);
    return head;
};
struct node *findkey(struct node *head,int key)
{
    if(head == NULL)
    return NULL;
if(head->key == key)
    return head;
return findkey(head->next,key);
};
void display(struct node *head)
{
    if(head == NULL)
        return;
    cout<<head->key<<" ";
    display(head->next);
}
// Floyd Cycle Detection
bool detectloop(struct node *head)
{
    struct node *slow = head,*fast = head;
    while(slow && fast && fast->next)
    {
        cout<<slow->key<<" ";
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main()
{
struct node *head = NULL;
for(int i=1;i<=20;++i)
head = addnode(head,i);

display(head);
struct node *x = findkey(head,20);
x->next = findkey(head,16);
cout<<endl;
if(detectloop(head)) cout<<"LOOP DETECTED"; else cout<<"LOOP NOT DETECTED";
return 0;
}

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
struct node *newlistnode(int key)
{
    struct node *temp = new node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
struct tnode *newtreenode(int key)
{
    struct tnode *temp = new tnode;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
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
void displaylist(struct node *start)
{
    if(start == NULL)
        return;
    cout<<start->key<<" ";
    displaylist(start->next);
}
void displaytree(struct tnode *root,int style)
{
    if(root == NULL)
        return;
    if(style < 0)
        cout<<root->key<<" ";
        displaytree(root->left,style);
    if(style == 0)
        cout<<root->key<<" ";
        displaytree(root->right,style);
    if(style > 0)
        cout<<root->key<<" ";
}
int len(struct node *start)
{
    if(start == NULL)
        return 0;
    return len(start->next)+1;
}
struct tnode *lltobst(struct node **start,int listlen)
{
    if(listlen<=0)
        return NULL;

    struct tnode *temp = lltobst(start,listlen/2);
    struct tnode *root = newtreenode((*start)->key);

    root->left = temp;
    *start = (*start)->next;
    root->right = lltobst(start,listlen - listlen/2 - 1);
    return root;
}
int main()
{
struct node *start = NULL;
start = addnode(start,5);
start = addnode(start,12);
start = addnode(start,31);
start = addnode(start,51);
start = addnode(start,92);
displaylist(start);
cout<<"\nLength : "<<len(start)<<endl;
struct tnode *root = NULL;
root = lltobst(&start,len(start));
displaytree(root,0);
return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
struct node
{
    int key;
    struct node *left,*right;
};
struct node *newnode(int key)
{
    struct node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
node *addnode(node *root,int key)
{
    if(root == NULL)
        return newnode(key);
    if(key<root->key)
        root->left = addnode(root->left,key);
    else
        root->right = addnode(root->right,key);
    return root;
}
void display(node* root ,int style)
{
    if(root == NULL)
        return;
    if(style<0) cout<<root->key<<" ";
    display(root->left,style);
    if(style==0) cout<<root->key<<" ";
    display(root->right,style);
    if(style>0) cout<<root->key<<" ";
}
node *construct(int a[],int l,int r)
{
    if(l>r)
        return NULL;
    int mid = (l+r)/2;
    node *root = newnode(a[mid]);
    root->left = construct(a,l,mid-1);
    root->right = construct(a,mid+1,r);
    return root;
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int a_size = sizeof(a)/sizeof(a[0]);
    node *root = construct(a,0,a_size-1);
    display(root,-1);
return 0;
}

#include<bits/stdc++.h>
using namespace std;
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
node *kth_smallest(node *root,int k)
{
    if(!root)
        return NULL;
    static int c = 0;
    if(c>k)
        return NULL;
    node *left = kth_smallest(root->left,k);
    if(left) return left;
    if(++c == k)
        return root;
    return kth_smallest(root->right,k);
}
int main()
{
    node *root = NULL;
    root = addnode(root,4);
    root = addnode(root,2);
    root = addnode(root,1);
    root = addnode(root,3);
    root = addnode(root,6);
    root = addnode(root,5);
    root = addnode(root,9);
    display(root,0);
    node *ans = kth_smallest(root,7);
    cout<<endl<<ans->key;
    return 0;
}

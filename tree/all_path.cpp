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
int path[MAX_N],len = 0;
void print(int path[],int len)
{
    for(int i=0;i<len;++i)
        cout<<path[i]<<" ";
    cout<<endl;
}
void showpath(node *root)
{
    path[len++] = root->key;
    if(root->left == NULL && root->right == NULL)
        {print(path,len);return;}
    showpath(root->left);
    --len;
    showpath(root->right);
    --len;
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
    root = addnode(root,7);
    showpath(root);
    return 0;
}

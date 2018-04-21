#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000
struct node
{
    int key;
    struct node *left,*right;
    int nodes_below;
};
struct node *newnode(int key)
{
    struct node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    temp->nodes_below = 0;
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
    if(style==0) cout<<root->nodes_below<<" ";
    display(root->right,style);
    if(style>0) cout<<root->key<<" ";
}
int fill_nodes(node *root)
{
    if(root == NULL)
        return 0;
    root->nodes_below = fill_nodes(root->left) + fill_nodes(root->right);
    return root->nodes_below + 1;
}
node* change_value(node *root)
{
    static int prev = -1;
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        {prev = root->key; return NULL;}
    root->left = change_value(root->left);
    root->nodes_below = prev;
    prev = root->key;
    root->right = change_value(root->right);
    return root;
}
int main()
{
    node *root = NULL;
    root = addnode(root,6);
    root = addnode(root,4);
    root = addnode(root,2);
    root = addnode(root,5);
    root = addnode(root,9);
    root = addnode(root,7);
    root = addnode(root,8);
    int dump = fill_nodes(root);
    display(root,0);
    cout<<endl;
    root = change_value(root);
    display(root,0);
}

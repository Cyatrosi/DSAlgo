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
node *bst_to_dll(node *root)
{
    if(root == NULL)
        return NULL;
    if(!root->right && !root->left)
        return root;
    node *l_list = bst_to_dll(root->left);
    node *r_list = bst_to_dll(root->right);
    root->left = root->right = NULL;
    root->right = r_list;
    if(r_list) r_list->left = root;
    node *it = l_list;
    if(it)
    {
        while(it->right)
            it = it->right;
        it->right = root;
    }
    root->left = it;
    return l_list;
}
void display_list(node *root)
{
    if(root == NULL)
        return;
    cout<<root->key<<" ";
    display_list(root->right);
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
node *dll = bst_to_dll(root);
cout<<"LL :"<<endl;
display_list(dll);
}

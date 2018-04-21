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
node * create_tree(node *root,long long seed,long long lim)
{
    if(seed == 0 || seed == lim)
        return NULL;
    cout<<"a";
    root = newnode(seed);
    root->left = create_tree(root->left,seed-1,lim);
    root->right = create_tree(root->right,seed+1,lim-1);
    return root;
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
display(root,0);
cout<<endl;
node *temp = NULL;
temp = create_tree(temp,2,3);
display(temp,0);
cout<<endl;
return 0;
}

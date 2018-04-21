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
bool identical(node *root_a,node *root_b)
{
    if(root_a == NULL && root_b == NULL)
        return true;
    if(root_a == NULL || root_b == NULL)
        return false;
    if(root_a->key != root_b->key)
    return false;
    return identical(root_a->left,root_b->left) && identical(root_a->right,root_b->right);
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
node *root_n = NULL;
root_n = addnode(root_n,4);
root_n = addnode(root_n,2);
root_n = addnode(root_n,1);
root_n = addnode(root_n,3);
root_n = addnode(root_n,6);
root_n = addnode(root_n,5);
root_n = addnode(root_n,7);
display(root,1);
cout<<endl;
display(root_n,0);
cout<<endl;
cout<<identical(root,root_n);
return 0;
}

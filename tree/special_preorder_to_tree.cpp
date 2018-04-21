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
void display(node* root ,int style)
{
    if(root == NULL)
        return;
    if(style<0) cout<<(char)root->key<<" ";
    display(root->left,style);
    if(style==0) cout<<(char)root->key<<" ";
    display(root->right,style);
    if(style>0) cout<<(char)root->key<<" ";
}
node *reconstruct(string s)
{
    static int i = 0;
    if(i>=s.length())
        return NULL;
    node *node_n = new node;
    node_n->key = (int)s[i];
    node_n->left = node_n->right = NULL;
    if(s[i] == 'L')
        return node_n;
    i = i+1;
    node_n->left = reconstruct(s);
    i = i+1;
    node_n->right = reconstruct(s);
    return node_n;
}
int main()
{
    string preorder = "ILILL";
    node *root = reconstruct(preorder);
    // print INORDER
    display(root,0);
    return 0;
}

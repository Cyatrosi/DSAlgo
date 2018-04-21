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
node *search_closest(node *root,int k)
{
    if(root == NULL)
        return NULL;
    node *ans = search_closest(root->left,k);
    if(ans)
    {if(abs(k-root->key)<abs(ans->key - k))
        ans = root;
    }
    else
        ans = root;
    node *right_ans = search_closest(root->right,k);
    if(right_ans)
    {
    if(abs(k-right_ans->key)<abs(ans->key - k))
        ans = right_ans;
    }
    return ans;
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
    node *nearest = search_closest(root,10);
    cout<<nearest->key;
    return 0;
}

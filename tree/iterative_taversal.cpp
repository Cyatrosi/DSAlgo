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
void preorder(node *root)
{
    stack<node*> s;
    while(1)
    {
        while(root){
        cout<<root->key<<" ";
        s.push(root);
        root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        s.pop();
        root = root->right;
    }
    cout<<endl;
}
void inorder(node *root)
{
    stack<node*> s;
    while(1)
    {
        while(root){
        s.push(root);
        root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        cout<<root->key<<" ";
        s.pop();
        root = root->right;
    }
    cout<<endl;
}
void postorder(node *root)
{
    stack<node*> s;
    while(1)
    {
        while(root){
        s.push(root);
        root = root->left;
        }
        if(s.empty())
            break;
        root = s.top();
        cout<<root->key<<" ";
        s.pop();
        if(root->right)
            s.push(root->right);
        root = root->right;
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void levelorder(node *root)
{
    queue<pair<node*,int> > q;
    pair<node*,int> p;
    q.push(make_pair(root,0));
    int level = 0;
    struct node *temp;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.second!=level)
        {
            cout<<endl;
            level = p.second;
        }
        temp = p.first;
        cout<<temp->key<<" ";
        if(temp->left)
            q.push(make_pair(temp->left,p.second+1));
        if(temp->right)
            q.push(make_pair(temp->right,p.second+1));
    }
    cout<<endl;
}
void zigzag(node *root)
{
    queue<pair<node*,int> > q;
    pair<node*,int> p;
    q.push(make_pair(root,0));
    int level = 0;
    bool rev = false;
    stack<int> s;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(level!=p.second)
        {
            if(rev)
                while(!s.empty())
                    {cout<<s.top()<<" ";s.pop();}
            rev = !rev;
            cout<<endl;level = p.second;
        }
        if(rev)
            s.push((p.first)->key);
        else
        cout<<(p.first)->key<<" ";
        if((p.first)->left)
            q.push(make_pair((p.first)->left,p.second+1));
        if((p.first)->right)
            q.push(make_pair((p.first)->right,p.second+1));
    }
    cout<<endl;
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
    preorder(root);
    postorder(root);
    levelorder(root);
    zigzag(root);
    return 0;
}

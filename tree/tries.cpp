#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
    struct TrieNode *children[26];
    bool isLeaf;
    int mark;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = new TrieNode;

    if (pNode)
    {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
    pNode->mark = 0;
    return pNode;
}
TrieNode* insert(struct TrieNode *root, string s,int i)
{
    if(i == s.length())
    {
        TrieNode *last_node = getNode();
        last_node->isLeaf = true;
        last_node->mark = 1;
        return last_node;
    }
    int index = s[i]-97;
    TrieNode *child = root->children[index];
    if(child == NULL)
    {
     root->children[index] = getNode();
    }
    root->children[index] = insert(root->children[index],s,i+1);
    root->mark+=1;
    return root;
}
int search(struct TrieNode *root, string s,int index)
{
    if(index == s.length())
        return root->mark;
    if(root->children[s[index]-97] == NULL)
        return 0;
    return search(root->children[s[index]-97],s,index+1);
}
int main() {
    TrieNode *root = getNode();
    long long n;
    cin>>n;
    string s,type;
    while(n--)
    {
        cin>>type>>s;
        if(type == "add")
        {
            root = insert(root,s,0);
        }
        else
        {
            cout<<search(root,s,0)<<endl;
        }
    }
    return 0;
}
/*
Sample Input

4
add hack
add hackerrank
find hac
find hak

Sample Output

2
0*/

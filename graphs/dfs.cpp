#include<bits/stdc++.h>
using namespace std;
#define V 4
vector<int> edges[V];
void addEdge(int u,int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}
void dfsRec(int src,bool visited[])
{
    if(visited[src])
        return;
    cout<<src<<" ";
    visited[src] = true;
    for(vector<int>::iterator it = edges[src].begin();it!=edges[src].end();++it)
        if(!visited[*it])
            dfsRec(*it,visited);
}
dfs(int src)
{
    bool visited[V] = {0};
    dfsRec(src,visited);
}
int main()
{
addEdge(0,1);
addEdge(0,2);
addEdge(1,2);
addEdge(2,0);
addEdge(2,3);
addEdge(3,3);
dfs(2);
return 0;
}

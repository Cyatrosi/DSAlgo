#include<bits/stdc++.h>
using namespace std;
#define V 4
vector<int> edges[V];
void addEdge(int u,int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}
void APRec(int src,int low[],int dfsnum[],bool visited[],bool ap[],int parent[])
{
    static int counter = 0;
    visited[src] = true;
    low[src] = dfsnum[src] = ++counter;
    int child = 0;
    for(vector<int>::iterator it = edges[src].begin();it!=edges[src].end();++it)
     {
         if(!visited[*it])
         {
             ++child;
             parent[*it] = src;
             APRec(*it,low,dfsnum,visited,ap,parent);
             low[src] = min(low[src],low[*it]);

             if(parent[src] == -1 && child>1)
                ap[src] = true;

             if(parent[src]!= -1 && low[*it]>=dfsnum[src])
                ap[src] = true;
         }
         else
         {
             if((*it)!=parent[src])
                low[src] = min(low[src],dfsnum[*it]);
         }
     }
}
AP()
{
    bool visited[V],ap[V];
    int low[V],dfsnum[V],parent[V];
    for(int i=0;i<V;++i)
        {
            parent[i] = -1;
            visited[i] = false;
            ap[i] = false;
        }
    for(int i=0;i<V;++i)
        APRec(i,low,dfsnum,visited,ap,parent);
    cout<<"Articulation Point :\n";
    for(int i=0;i<V;++i)
        if(ap[i])
            cout<<i<<" ";
}
int main()
{
addEdge(0,1);
addEdge(1,2);
addEdge(2,3);
AP();
return 0;
}

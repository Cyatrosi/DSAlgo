#include<bits/stdc++.h>
using namespace std;
#define V 4
vector<int> edges[V];
vector<pair<int,int> > ae;
void addEdge(int u,int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}
void APRec(int src,int low[],int dfsnum[],bool visited[],int parent[])
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
             APRec(*it,low,dfsnum,visited,parent);
             low[src] = min(low[src],low[*it]);

             if(low[*it]>dfsnum[src])
                ae.push_back(make_pair(src,*it));
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
    bool visited[V];
    int low[V],dfsnum[V],parent[V];
    for(int i=0;i<V;++i)
        {
            parent[i] = -1;
            visited[i] = false;
        }
    for(int i=0;i<V;++i)
        if(!visited[i])
            APRec(i,low,dfsnum,visited,parent);
    cout<<"Articulation Point :\n";
    for(vector<pair<int,int> >::iterator it = ae.begin();it!=ae.end();++it)
            cout<<it->first<<" "<<it->second<<endl;
}
int main()
{
addEdge(0,1);
addEdge(1,2);
addEdge(2,3);
AP();
return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define V 5
int find_minkey(bool visited[],int dist[])
{
    int min_dist = INT_MAX,index;
    for(int i=0;i<V;++i)
    {
        if(!visited[i] && dist[i]<min_dist)
        {
            min_dist = dist[i];
            index = i;
        }
    }
    return index;
}
void print(int graph[V][V],int parent[])
{
    for(int i=1;i<V;++i)
        cout<<i<<" "<<parent[i]<<"->"<<graph[parent[i]][i]<<endl;
}
void prims(int graph[V][V])
{
    int parent[V],dist[V];
    bool visited[V] = {0};
    for(int i=0;i<V;++i)
        dist[i] = INT_MAX;
    dist[0] = 0;
    parent[0] = -1;
    int p;
    for(int i=0;i<V;++i)
    {
        p = find_minkey(visited,dist);
        visited[p] = true;
        for(int j=0;j<V;++j)
        {
            if(graph[p][j] && graph[p][j]< dist[j])
                {
                    parent[j] = p;
                    dist[j] = graph[p][j];
                }
        }
    }
    print(graph,parent);
}
int main()
{
int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    prims(graph);
    return 0;
}

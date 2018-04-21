#include<bits/stdc++.h>
using namespace std;
#define V 9
int min_parent(bool visited[],int dist[])
{
    int min_dist = INT_MAX,index;
    for(int i=0;i<V;++i)
        if(!visited[i] && min_dist>dist[i])
            {min_dist = dist[i];index = i;}
    return index;
}
void print(int dist[])
{
    for(int i=0;i<V;++i)
        cout<<i<<" "<<dist[i]<<endl;
}
void dijkstra(int graph[V][V],int src)
{
    int dist[V] = {0};
    for(int i=0;i<V;++i)
        dist[i] = INT_MAX;
    bool visited[V] = {0};
    dist[src] = 0;
    int parent;
    for(int i=0;i<V;++i)
    {
        parent = min_parent(visited,dist);
        visited[parent] = true;
        for(int j=0;j<V;++j)
        {
            if(graph[parent][j] && !visited[j])
                dist[j] = min(dist[j],dist[parent] + graph[parent][j]);
        }
    }
    print(dist);
}
int main()
{
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
   dijkstra(graph,0);
return 0;
}

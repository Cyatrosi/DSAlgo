#include<bits/stdc++.h>
using namespace std;
map<pair<long long,long long>,long long> e;
void bellamnford(long long V,long long E,long long src)
{
    long long dist[V];
    for(long long i=0;i<V;++i)
        dist[i] = INT_MAX;
    dist[src] = 0;

    pair<long long,long long> edge;
    for(long long u = 0;u<V-1;++u)
    {
        for(map<pair<long long,long long>,long long>::iterator it = e.begin();it!=e.end();++it){
            edge = it->first;
            if(dist[edge.first]!=INT_MAX)
                dist[edge.second] = min(dist[edge.second],dist[edge.first] + it->second);
        }
    }
    bool cycle = false;
    for(map<pair<long long,long long>,long long>::iterator it = e.begin();it!=e.end();++it)
    {
        edge = it->first;
        if(dist[edge.first]!=INT_MAX && dist[edge.second] > dist[edge.first] + it->second)
            {cycle = true;break;}
    }
    if(cycle)
    {
        cout<<"DETECTED NEGATIVE CYCLE !!";
        return;
    }
    for(long long i = 0;i<V;++i)
        cout<<i<<" "<<dist[i]<<endl;
}
int main()
{
long long V = 5,E = 8;
e[make_pair(0,1)] = -1;
e[make_pair(0,2)] = 4;
e[make_pair(1,2)] = 3;
e[make_pair(1,3)] = 2;
e[make_pair(1,4)] = 2;
e[make_pair(3,2)] = 5;
e[make_pair(3,1)] = 1;
e[make_pair(4,3)] = -3;
bellamnford(V,E,0);
return 0;
}

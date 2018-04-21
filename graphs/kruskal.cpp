#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > > edges,mst;
void print()
{
    for(vector<pair<int,pair<int,int> > >::iterator it = mst.begin();it!=mst.end();++it)
        cout<<(it->second).first<<" "<<(it->second).second<<"->"<<it->first<<endl;
}
void kruskal(int V)
{
    sort(edges.begin(),edges.end());
    bool is_included[V] = {0};
    pair<int,int> p;
    for(vector<pair<int,pair<int,int> > >::iterator it = edges.begin();it!=edges.end();++it)
    {
        p = it->second;
        if(!is_included[p.first] || !is_included[p.second])
            mst.push_back(*it);
        is_included[p.first] = true;
        is_included[p.second] = true;
    }
    print();
}
int main()
{
int V = 4,E = 5;
edges.push_back(make_pair(10,make_pair(0,1)));
edges.push_back(make_pair(6,make_pair(0,2)));
edges.push_back(make_pair(5,make_pair(0,3)));
edges.push_back(make_pair(15,make_pair(1,3)));
edges.push_back(make_pair(4,make_pair(2,3)));
kruskal(V);
return 0;
}

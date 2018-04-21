#include<bits/stdc++.h>
using namespace std;
pair<int,int> maxLenSubArray(int a[],int n){
map<int,int> m;
m[0] = -1;
int z = 0,o = 0,len = -1,start = -1;
for(int i=0;i<n;++i){
    if(a[i] == 0) ++z;
    else ++o;
    if(m.find(z-o) == m.end())
        m[z-o] = i;
    else{
        if(i-m[z-o]>len){
            len = i-m[z-o];
            start = m[z-o]+1;
        }
    }
}
return make_pair(start,len);
}
int main(){
int n = 7;
int a[] = {0,1,0,1,0,1,0};
pair<int,int> p  = maxLenSubArray(a,n);
for(int i=p.first;i<p.first+p.second;++i)
    cout<<a[i]<<" ";
return 0;
}

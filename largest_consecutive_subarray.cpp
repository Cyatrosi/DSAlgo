#include<bits/stdc++.h>
using namespace std;
pair<int,int> ConsecArray(int a[],int n){
int mn,mx,len = -1,start = -1;
for(int i=0;i<n;++i){
    mn = INT_MAX,mx = INT_MIN;
    for(int j=i;j<n;++j){
        mn = min(mn,a[j]);
        mx = max(mx,a[j]);
        if(mx-mn == j-i){
            if((j-i)>len){
                len = j-i;
                start = i;
            }
        }
    }
}
return make_pair(start,len+1);
}
int main(){
int n,i;
cin>>n;
int a[n];
for(i=0;i<n;++i)
    cin>>a[i];
pair<int,int> p;
p = ConsecArray(a,n);
cout<<p.first<<" "<<p.second;
}

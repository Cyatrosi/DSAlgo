/*
Question : Given an array and a sum. Find a pair of array elements with sum equal to given sum.
Input: n,Sum -> Array
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> findPair(int a[],int n,int sum){
map<int,int> m;
for(int i=0;i<n;++i){
    if(m[sum-a[i]]!=0)
    return {m[sum-a[i]]-1,i};
m[a[i]] = i+1;
}
return {-1,-1};
}
int main(){
int n,sum;
cin>>n>>sum;
int a[n];
for(int i=0;i<n;++i) cin>>a[i];
pair<int,int> Indices = findPair(a,n,sum);
if(Indices == pair<int,int>(-1,-1))
    cout<<"Not Found";
else
    cout<<"Found at : "<<Indices.first<<" "<<Indices.second;
}

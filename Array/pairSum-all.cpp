/*
Question : Given an array and a sum. Find a pair of array elements with sum equal to given sum.
Input: n,Sum -> Array
*/
#include<bits/stdc++.h>
using namespace std;
void printPairs(int a[],int n,int sum){
map<int,vector<int> > m;
bool found = false;
for(int i=0;i<n;++i){
    if(m[sum-a[i]].size()!=0){
        found = true;
        for(auto x:m[sum-a[i]])
            cout<<x<<" "<<i<<endl;
    }
m[a[i]].push_back(i);
}
if(!found)
    cout<<"Not Found";
}
int main(){
int n,sum;
cin>>n>>sum;
int a[n];
for(int i=0;i<n;++i) cin>>a[i];
printPairs(a,n,sum);
}

#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int n,int b[],int m){
int i;
for(i=0;i<n;++i){
    if(a[i]>b[0]){
        a[i]^=b[0];
        b[0]^=a[i];
        a[i]^=b[0];
    int temp = b[0];
    int k;
    for(k=1;k<m && b[k]<temp;++k)
        b[k-1] = b[k];
    b[k-1] = temp;
    }
}
for(i=0;i<n;++i)
    cout<<a[i]<<" ";
cout<<endl;
for(i=0;i<m;++i)
    cout<<b[i]<<" ";
cout<<endl;
}
int main(){
int n,m,i;
cin>>n>>m;
int a[n],b[m];
for(i=0;i<n;++i)
    cin>>a[i];
for(i=0;i<m;++i)
    cin>>b[i];
    merge(a,n,b,m);
return 0;
}
/*
// Test Case
5 5
1 2 3 21 75
5 6 7 30 100
*/

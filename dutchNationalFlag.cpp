#include<bits/stdc++.h>
using namespace std;
void sortDutch(int a[],int n){
int l = 0,r = n-1;
while(l<r){
    while(a[l]==0 && l<n)
        ++l;
    while(a[r]!=0 && r>=0)
        --r;
    if(l>=r)
        break;
    int temp;
    temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}
l = 0;
while(a[l] == 0)
    ++l;
r = n-1;
while(l<r){
    while(a[l]==1 && l<n)
        ++l;
    while(a[r]!=1 && r>=0)
        --r;
    if(l>=r)
        break;
    int temp;
    temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}
}
int main(){
int n = 12;
int a[] = {0,1,2,2,1,0,0,2,0,1,1,0};
sortDutch(a,n);
for(auto x:a)
    cout<<x<<" ";
return 0;
}

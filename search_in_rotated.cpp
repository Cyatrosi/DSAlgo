#include<bits/stdc++.h>
using namespace std;
int search_index(int a[],int n,int k)
{
int l=0,h=n-1;
int mid;
while(l<=h)
{
    mid = (l+h)/2;
    if(a[mid] == k)
        return mid;
    else if(k<a[mid] && k>=a[l])
        h = mid-1;
    else
        l = mid+1;
}
return -1;
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;++i)
    cin>>a[i];
int k;
cin>>k;
int index = search_index(a,n,k);
if(index == -1)
    cout<<"Not Found !!";
else
    cout<<index;
return 0;
}

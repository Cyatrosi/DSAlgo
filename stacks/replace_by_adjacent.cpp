#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n,i;
cin>>n;
long long a[n];
for(i=0;i<n;++i)
    cin>>a[i];
long long nearest_max[n];
nearest_max[n-1] = a[n-1];
for(i=n-2;i>=0;--i)
    nearest_max[i] = max(nearest_max[i+1],a[i]);
for(i=0;i<n;++i)
    cout<<nearest_max[i]<<" ";
return 0;
}

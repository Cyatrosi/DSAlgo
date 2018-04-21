#include<bits/stdc++.h>
using namespace std;
long long findduplicate(long long a[],long long n)
{
long long sum = 0,i;
for(i=0;i<n;++i) sum+=a[i];
return sum - (n*(n-1)/2);
}
int main()
{
long long n,i;
cin>>n;
long long a[n];
for(i=0;i<n;++i) cin>>a[i];
cout<<findduplicate(a,n);
return 0;
}

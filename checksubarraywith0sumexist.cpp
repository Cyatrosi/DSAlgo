#include<bits/stdc++.h>
using namespace std;
set<long long> s;
bool subarraywithzerosumexist(long long a[],long long n)
{
long long sum,i;
sum = 0;
s.insert(0LL);
for(i=1;i<=n;++i)
{
    sum+=a[i];
    if(s.find(sum)!=s.end())
    return true;
    s.insert(sum);
}
return false;
}

int main()
{
long long n,i;
cin>>n;
long long a[n+1];
for(i=1;i<=n;++i) cin>>a[i];
if(subarraywithzerosumexist(a,n))
    cout<<"Sub-Array with 0 sum exists";
else
    cout<<"Sub-Array with 0 sum doesn't exists";
return 0;
}

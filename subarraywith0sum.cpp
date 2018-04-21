#include<bits/stdc++.h>
using namespace std;
multimap<long long,long long> m;
void subarraywithzerosum(long long a[],long long n)
{
long long sum,i;
sum = 0;
m.insert(make_pair(sum,0LL));
multimap<long long,long long>::iterator it;
for(i=1;i<=n;++i)
{
    sum += a[i];
    it = m.find(sum);
        while(it!=m.end() && it->first == sum)
        {
            cout<<"["<<(it->second)+1<<" ... "<<i<<"]"<<endl;
            ++it;
        }
    m.insert(make_pair(sum,i));
}
}

int main()
{
long long n,i;
cin>>n;
long long a[n+1];
for(i=1;i<=n;++i) cin>>a[i];
subarraywithzerosum(a,n);
return 0;
}

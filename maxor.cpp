#include<bits/stdc++.h>
using namespace std;
bool check(long long n)
{
    long double a = log(n+1)/log(2);
    return (ceil(a) == floor(a));
}
long long print(long long n)
{
    long long ans = 0;
    for(long long i=0;i<n;++i)
        if((n|i) <= n)
            ++ans;
    return ans;
}
int main()
{/*
long long t;
cin>>t;
while(t--)
{
    long long n;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    long long ans = 0;
    for(long long i=0;i<n;++i)
        if(check(a[i]))
            ans+=i;
cout<<ans<<endl;
}*/
for(long long i=1;i<=50;++i)
    cout<<print(i)<<" -> "<<i<<endl;
return 0;
}

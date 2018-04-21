#include<bits/stdc++.h>
using namespace std;
long double fact(long double n)
{
    long double s = 0;
    for(long double i=1;i<=n;++i)
        s+=log(i);
    return exp(s);
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long double n,ans,f;
        cin>>n;
        cout<<fact(n)<<endl;
        ans = n*log(n) - n + 1;
        f = 2*exp(ans);
        cout<<f<<endl;
    }
}

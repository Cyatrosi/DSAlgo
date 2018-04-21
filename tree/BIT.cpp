#include <bits/stdc++.h>
using namespace std;
long long BIT[100001] = {0};
long long n;
void update(long long i,long long val)
{
    for(;i<=n;i+=i&(-i))
        BIT[i]+=val;
}
long long query(long long x)
{
    long long sum = 0;
    for(;x>0;x-=x&(-x))
        sum+=BIT[x];
    return sum;
}
int main()
{
    cin>>n;
    long long a[n];
    for(long long i=1;i<=n;++i)
        cin>>a[i];
    for(long long i=1;i<=n;++i)
        update(i,(long long)(a[i]%2==0));
    long long q;
    cin>>q;
    long long type,x,y;
    while(q--){
        cin>>type>>x>>y;
        if(type == 0)
            {
                if((a[x]+y)%2 != 0)
                    if(a[x]%2 == 1 && y%2 == 0) update(x,1LL);
                    else update(x,-1LL);
                a[x] = y;
            }
        else if(type == 1)
            cout<<query(y)-query(x-1)<<endl;
        else
            cout<<(y-x+1)-query(y)+query(x-1)<<endl;
    }
    return 0;
}

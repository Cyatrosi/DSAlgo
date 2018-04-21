#include<bits/stdc++.h>
using namespace std;
void maxsubarray(long long a[],long long n)
{
    set<long long> duplicate;
    long long min_val,max_val,i,j;
    for(i=0;i<n;++i)
    {
        duplicate.clear();
        duplicate.insert(a[i]);
        min_val = a[i];
        max_val = a[i];
        for(j=i+1;j<n;++j)
        {

        }
    }
}
int main()
{
long long n,i;
cin>>n;
long long a[n];
for(i=0;i<n;++i) cin>>a[i];

return 0;
}

#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> pairwithsum_n2(long long a[],long long n,long long sum)
{
    long long i,j;
for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
        if(a[i]+a[j] == sum)
                return make_pair(i,j);
    return make_pair(-1,-1);
}
pair<long long,long long> pairwithsum_nlogn(long long a[],long long n,long long sum)
{
    sort(a,a+n);
    long long i,l,h,mid;
for(i=0;i<n;++i)
    {
        l = i+1;
        h = n-1;
        while(l<=h)
        {
            mid = (l+h)/2;
            if(sum-a[i] == a[mid])
                return make_pair(i,mid);
            else if(sum-a[i] > a[mid])
                l = mid+1;
            else
                h = mid-1;
        }
    }
    return make_pair(-1,-1);
}

int main()
{
    long long n,sum,i;
    cin>>n>>sum;
long long a[n];
for(i=0;i<n;++i)
    cin>>a[i];
pair<long long,long long> sum_pair;

// O(n^2)
sum_pair = pairwithsum_n2(a,n,sum);
cout<<sum_pair.first<<" "<<sum_pair.second<<endl;

// O(nlog(n))
sum_pair = pairwithsum_nlogn(a,n,sum);
cout<<sum_pair.first<<" "<<sum_pair.second<<endl;

return 0;
}

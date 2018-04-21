#include <bits/stdc++.h>
using namespace std;
long long find_min_diff(long long a[],long long n)
{
    long long sum = 0;
    for(long long i=0;i<n;++i)
        sum+=a[i];
    bool dp[n+1][sum+1];
    for(long long i=0;i<=sum;++i)
        dp[0][i] = false;
    for(long long i=0;i<=n;++i)
        dp[i][0] = true;
    for(long long i=1;i<=n;++i)
    {
        for(long long j=1;j<=sum;++j)
        {
            if(a[i-1]<=j)
             dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    long long l,h;
    h = l = sum/2;
    while(!dp[n][l] && l>=0) --l;
    while(!dp[n][h] && h<=sum) ++h;
    return min(abs(sum-2*l),abs(2*h-sum));
}
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long a[n];
	    for(long long i=0;i<n;++i)
	        cin>>a[i];
	    int min_diff = find_min_diff(a,n);
	    cout<<min_diff<<endl;
	}
	return 0;
}

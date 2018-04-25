#include<bits/stdc++.h>
using namespace std;
long long minMul(long long p[],long long n){
    long long dp[n][n],i,j,k,l;
    for(i=1;i<n;++i) dp[i][i] = 0;
    for(l = 1;l<n-1;++l){
        for(i=1;i<n-l;++i){
            j = i+l;
            dp[i][j] = LONG_MAX;
            for(k=i;k<j;++k)
            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
        }
    }
    return dp[1][n-1];
}
int main()
 {
	long long t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long p[n];
	    for(long long i=0;i<n;++i) cin>>p[i];
	    cout<<minMul(p,n)<<endl;
	}
	return 0;
}

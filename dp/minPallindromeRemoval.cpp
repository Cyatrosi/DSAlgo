#include<bits/stdc++.h>
using namespace std;
long long minPalRemv(string s){
long long n = s.length(),i,j,gap;
long long dp[n][n];
for(i=0;i<n;++i)
    dp[i][i] = 1;
for(i=0;i<n-1;++i)
    if(s[i] == s[i+1])
        dp[i][i+1] = 1;
    else
        dp[i][i+1] = 2;
for(gap = 2;gap<n;++gap)
    for(i=0,j=gap;j<n;++j,++i)
        if(s[i] == s[j])
            dp[i][j] = min(dp[i+1][j-1],min(1+dp[i+1][j],1+dp[i][j-1]));
        else
            dp[i][j] = min(dp[i+1][j-1]+2,min(dp[i+1][j]+1,dp[i][j-1]+1));
    return dp[0][n-1];
}
int main(){
string s;
cin>>s;
cout<<minPalRemv(s);
return 0;
}

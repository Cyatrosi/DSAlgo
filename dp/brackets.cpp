#include<bits/stdc++.h>
using namespace std;
long long Ways(string a,string b){
    long long n,m;
    n = a.length();
    m = b.length();
    pair<long long,long long> dp[n][m];
    long long i,j;
    dp[0][0].first = 0;
    dp[0][0].second = 0;

    for(i=1;i<=n;++i){
        dp[i][0].second = (a[i-1] == '(')?dp[i-1][0].second+1:dp[i-1][0].second-1;
        if(dp[i][0].second == 0)
            dp[i][0].first = 1;
        else
            dp[i][0].first = 0;
    }
    for(i=1;i<=m;++i){
        dp[0][i].second = (b[i-1] == '(')?dp[0][i-1].second+1:dp[0][i-1].second-1;
        if(dp[0][i-1].second == 0)
            dp[0][i].first = 1;
        else
            dp[0][i].first = 0;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j){
            dp[i][j].second = dp[i-1][j].second + dp[i][j-1].second;
            if(dp[i][j].second == 0)
                dp[i][j].first = dp[i-1][j-1].first+1;
            else
                dp[i][j].first = 0;
        }
    return dp[n][m].first;
}
int main(){
string a,b;
cin>>a>>b;
cout<<Ways(a,b);
}

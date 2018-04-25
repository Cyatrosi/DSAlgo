// Q : print Longest Common Subsequence between two strings X and Y. The subsequence may not be necessarily contiguous.
#include<bits/stdc++.h>
using namespace std;
long long LCS(string a,string b){
long long n = a.length(),m = b.length(),i,j;
long long dp[n+1][m+1];
for(i=0;i<=n;++i) dp[i][0] = 0;
for(i=0;i<=m;++i) dp[0][i] = 0;
for(i=1;i<=n;++i)
    for(j=1;j<=m;++j){
        if(a[i-1] == b[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
i = n;
j = m;
stack<char> s;
while(i>0 && j>0){
    if(a[i-1] == b[j-1])
        {[s.push(a[i-1]);--i;--j;}
    else{

    }
}
}
int main(){
string a,b;
cin>>a>>b;
printLCS();
return 0;
}

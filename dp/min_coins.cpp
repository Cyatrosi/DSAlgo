#include<bits/stdc++.h>
using namespace std;
int min_coins(int coins[],int n,int change)
{
    int dp[change+1];
    for(int i=1;i<=change;++i)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i=1;i<=change;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i>=coins[j])
            {
                int prev = dp[i-coins[j]];
                if(prev!=INT_MAX)
                    dp[i] = min(dp[i],prev+1);
            }
        }
    }
    return dp[change];
}
int main()
{
int coins[] = {9,5,6,1};
int n = sizeof(coins)/sizeof(coins[0]);
int change = 11;
cout<<min_coins(coins,n,change);
return 0;
}

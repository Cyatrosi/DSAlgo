/*
Given an NxN chessboard and a Knight at position (x,y).
The Knight has to take exactly K steps, where at each step it chooses any of the 8 directions uniformly at random.
What is the probability that the Knight remains in the chessboard after taking K steps, with the
condition that it can’t enter the board again once it leaves it.
*/
#include<bits/stdc++.h>
using namespace std;
#define N 8
bool valid(long long i,long long j){
if(i<0 || j<0 || i>=N || j>=N)
    return false;
return true;
}
long double KnightOnChessBoard(long long x,long long y,long long k){
long long dx[N] = {1,1,2,2,-1,-1,-2,-2};
long long dy[N] = {2,-2,1,-1,2,-2,1,-1};
long double dp[N][N][k+1];
long long i,j,l,m;
for(i=0;i<N;++i)
    for(j=0;j<N;++j)
        dp[i][j][0] = 1.0;
for(l=1;l<=k;++l){
    for(i=0;i<N;++i){
        for(j=0;j<N;++j){
            dp[i][j][l] = 0.0;
            for(m=0;m<N;++m)
                if(valid(i+dx[m],j+dy[m])){
                    //cout<<i+dx[m]<<" "<<j+dy[m]<<endl;
                    dp[i][j][l]+=dp[i+dx[m]][j+dy[m]][l-1];
                }
//            cout<<dp[i][j][l]<<" "<<i<<" "<<j<<" "<<l<<endl;
            dp[i][j][l]/=8.0;
        }
    }
}
return dp[x][y][k];
}
int main(){
long long x,y,k;
cin>>x>>y>>k;
cout<<KnightOnChessBoard(x,y,k);
return 0;
}

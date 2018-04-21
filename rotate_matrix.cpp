#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long a[n][n],i,j,k;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            cin>>a[i][j];
    long long level = n-1,x,y,temp,buf;
    k = 0;
    for(long long level = n-1;level>1;--level)
    {
        for(i=k;i<level;++i)
        {
            cout<<i<<" "<<k<<" "<<level<<endl;
            x = k;
            y = i;
            buf = a[x][y];
            for(j=0;j<3;++j)
            {
                a[x][y] = a[n-1-y][x];
                temp = x;
                x = n-1-y;
                y = temp;
            }
            a[x][y] = buf;
        }
        ++k;
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
	return 0;
}
/*
Method to rotate matrix
--> Take Matrix transpose
--> Take it's mirror image about y axis i.e. swap a[i][j] and a[i][n-j-1];
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int n = a.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            a[i][j] = a[i][j]^a[j][i];
            a[j][i] = a[i][j]^a[j][i];
            a[i][j] = a[i][j]^a[j][i];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            a[i][j] = a[i][j]^a[i][n-j-1];
            a[i][n-j-1] = a[i][j]^a[i][n-j-1];
            a[i][j] = a[i][j]^a[i][n-j-1];
        }
    }
    return a;
}
*/

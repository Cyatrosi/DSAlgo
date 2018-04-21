#include<bits/stdc++.h>
using namespace std;
int main()
{
long long size,n;
cin>>size;
n = size-2;
int a[size];
for(int i=0;i<size;++i)
    cin>>a[i];
int xy=0,x=0,y=0;
for(int i=0;i<size;++i)
    xy^=a[i];
for(int i=1;i<=n;++i)
    xy^=i;
int right_bit = xy & (~(xy-1));
cout<<right_bit<<endl;
for(int i=0;i<size;++i)
    if(a[i] & right_bit)
        x^=a[i];
    else
        y^=a[i];
for(int i=1;i<=n;++i)
{
    if(i & right_bit)
        x^=i;
    else
        y^=i;
}
cout<<x<<" "<<y;
return 0;
}

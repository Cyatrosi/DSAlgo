#include<bits/stdc++.h>
using namespace std;
void sortbinary(bool a[],long long n)
{
long long l = 0,h = n-1;
bool swapvar;
while(l<h)
{
    while(a[l] == 0) ++l;
    while(a[h] == 1) --h;
    if(l<h)
    {
        swapvar = a[l];
        a[l] = a[h];
        a[h] = swapvar;
    }
}
}
int main()
{
long long n,i;
cin>>n;
bool a[n];
for(i=0;i<n;++i) cin>>a[i];
sortbinary(a,n);
cout<<endl;
for(i=0;i<n;++i) cout<<a[i]<<" ";
return 0;
}

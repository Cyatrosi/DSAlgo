#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
    bool flag = true;
    int i=0,j=0;
    while(i<a.length() && j<b.length())
    {
        if(a[i]!=b[j])
        {
            if(flag) {
                    flag = false;
                    if(a[i+1] == b[j]) ++i;
                    else if(a[i] == b[j+1]) ++j;
                    else if(a[i+1] == b[j+1]) {++j;++i;}
                    else return false;
            }
            else
                return false;
        }
        else
        {++i;++j;}
    }
    if(flag)
    {
        return (abs(a.length()-b.length()) <= 1);
    }
    else
    {
        return (i == a.length() && j == b.length());
    }
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
string a,b;
cin>>a>>b;
cout<<check(a,b)<<endl;
    }
return 0;
}

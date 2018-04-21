#include<bits/stdc++.h>
using namespace std;
// Q; remove all adjacent duplicates
// Ex. Input: careermonk Output: cmonk
// Ex. Input: mississippi Output: m
stack<char> c;
void remove_adj()
{
    if(c.empty())
        return;
    char ch = c.top();
    c.pop();
    remove_adj();
    if(!c.empty()){
    if(c.top() == ch)
        c.pop();
    else
        c.push(ch);
    }else
    c.push(ch);
}
int main()
{
string s;
cin>>s;
reverse(s.begin(),s.end());
for(int i=0;i<s.length();++i)
    c.push(s[i]);
remove_adj();
while(!c.empty())
{
    cout<<c.top();
    c.pop();
}
return 0;
}

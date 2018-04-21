#include<bits/stdc++.h>
using namespace std;
queue<int> q;
void rev()
{
    if(q.empty())
        return;
    int x = q.front();

}
int main()
{
int x;
while(cin>>x)
    q.push(x);
while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
return 0;
}

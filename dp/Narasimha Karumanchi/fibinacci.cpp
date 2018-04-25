// Q : Print Fibonacci series with F(0) = 1, F(1) = 1
#include<bits/stdc++.h>
using namespace std;
long long Fibo(long long n){
if(n==0 || n == 1)
    return 1;
long long a = 1,b = 1,c;
for(long long i=1;i<n;++i){
    c = a+b;
    a = b;
    b = c;
}
return c;
}
int main(){
long long num;
cin>>num;
cout<<Fibo(num);
return 0;
}

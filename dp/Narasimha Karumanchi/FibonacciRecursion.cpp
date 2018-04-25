#include<bits/stdc++.h>
using namespace std;
int printFibo(int n,char print){
if(n == 0 || n==1){
    if(print == 'y') cout<<"1 1 ";
    return 1;
}
int c;
if (print == 'y'){
    c = printFibo(n-1,'y') + printFibo(n-2,'n');
    cout<<c<<" ";
    }
else
    c = printFibo(n-1,'n') + printFibo(n-2,'n');
return c;
}
int main(){
printFibo(10,'y');
return 0;
}

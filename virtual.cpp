#include<bits/stdc++.h>
using namespace std;
class A{
    int x;
public:
    A(){
        x = 0;
    }
    virtual void f() = 0;
};
class B{
    int x;
public:
    B(){
    x = 0;
    }
    virtual void f() = 0;
};
class C:public A,public B{
    int x;
public:
    C(){
       x = 0;
    }
    void f(){
    cout<<"C\n";
    }
    void poke(){
    cout<<"POKE\n";
    }
};
void check(const int &x) const{
cout<<x;
}
int main(){
const int x = 1;
check(x);
return 0;
}

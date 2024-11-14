#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(!b) return x=1,y=0,a;
    int r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
int main()
{
    int a,b;cin>>a>>b;
    int x0,y0;
    int gd=exgcd(a,b,x0,y0);
    //ax+by=gd(c)
    cout<<x0<<' '<<y0<<' '<<gd<<'\n';
    //x=x0*c/gcd(a,b)+k*b/gcd(a,b)
    //y=y0*c/gcd(a,b)-k*a/gcd(a,b)
}
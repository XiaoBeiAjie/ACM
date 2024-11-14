#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1;y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
ll excrt(vector<ll>&r,vector<ll>&m)
{
    //m是模数
    ll x=r[0],y1,y2,LCM=m[0];
    for(int i=1;i<(int)r.size();++i)
    {
        ll b=m[i],c=((r[i]-x)%b+b)%b;
        ll GCD=exgcd(LCM,b,y1,y2);
        if(c%GCD) return -1;
        y1=y1*(c/GCD)%(b/GCD);
        x+=LCM*y1;
        LCM*=b/GCD;
        x=(x%LCM+LCM)%LCM;
    }
    return x;
}
int main()
{
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    cout<<excrt(b,a)<<'\n';
}
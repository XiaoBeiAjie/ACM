#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll Exgcd(ll aa,ll bb,ll &x,ll &y)
{
    if(bb==0) {x=1;y=0;return aa;}
    ll d=Exgcd(bb,aa%bb,y,x);
    y-=(aa/bb)*x;
    return d;
};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    auto solve=[]()->void
    {
        ll a,b,z;cin>>a>>b>>z;
        ll x0,y0;
        ll gd=Exgcd(a,b,x0,y0);
        if(z%gd) return cout<<-1<<'\n',void();
        x0*=z/gd;y0*=z/gd;
        ll ans=9e18;b/=gd;a/=gd;
        ll l=x0/b,r=y0/a;
        if(-x0%b)
        {
            if(x0<0) ++l;
        }
        if(y0%a)
        {
            if(y0<0) --r;
        }
        if(r>=l)
        {
            if(b>=a) ans=min(ans,2ll*(x0+l*b+y0-l*a));
            else ans=min(ans,2ll*(x0+r*b+y0-r*a));
        }
        l=-x0/b;
        if(x0%b)
        {
            if(x0<0) ++l;
        }
        r=y0/a;
        if(y0%a)
        {
            if(y0>0) ++r;
        }
        l=max(l,r);
        ans=min(ans,2ll*(x0+l*b-y0+l*a)-1);
        r=-x0/b;
        if(x0%b)
        {
            if(x0>0) --r;
        }
        l=y0/a;
        if(y0%a)
        {
            if(y0<0) --l;
        }
        r=min(l,r);
        ans=min(ans,2ll*(-x0-r*b+y0-r*a)-1);
        cout<<ans<<'\n';
    };
    while(t--) solve();
}
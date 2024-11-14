#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Rhpr
{
    ll max_factor,n;
    Rhpr(ll m){n=m;max_factor=0;}
    ll quick_pow(ll x,ll p,ll mod,ll ans=1) 
    {  
        while(p) 
        {
            if(p&1) ans=(__int128)ans*x%mod;
            x=(__int128)x*x%mod;
            p>>=1;
        }
        return ans;
    }
    bool Miller_Rabin(ll p) 
    {   
        if(p<2) return 0;
        if(p==2) return 1;
        if(p==3) return 1;
        ll d=p-1,r=0;
        while(!(d&1)) ++r,d>>=1;
        for(ll k=0;k<10;++k) 
        {
            ll a=rand()%(p-2)+2;
            ll x=quick_pow(a,d,p);
            if(x==1||x==p-1) continue;
            for(int i=0;i<r-1;++i) 
            {
                x=(__int128) x*x%p;
                if(x==p-1) break;
            }
            if(x!=p-1) return 0;
        }
        return 1;
    }
    ll Pollard_Rho(ll x) 
    {
        ll s=0,t=0,val=1;
        ll c=(ll)rand()%(x-1)+1;
        int step=0,goal=1;
        for(goal=1;;goal*=2,s=t,val=1) 
        {   
            for(step=1;step<=goal;++step) 
            {
                t=((__int128) t*t+c)%x;
                val=(__int128) val*abs(t-s)%x;
                if((step%127)==0) 
                {
                    ll d=__gcd(val,x);
                    if(d>1) return d;
                }
            }
            ll d=__gcd(val,x);
            if(d>1) return d;
        }
    }
    void fac(ll x) 
    {
        if(x<=max_factor||x<2) return;
        if(Miller_Rabin(x)) return max_factor=max(max_factor,x),void();
        ll p=x;
        while(p>=x) p=Pollard_Rho(x);
        while((x%p)==0) x/=p;
        fac(x),fac(p);
    }
};
int main() 
{
    int t;cin>>t;
    while(t--) 
    {
        srand((unsigned)time(NULL));
        ll n;cin>>n;Rhpr rhp(n);rhp.fac(n);
        if(rhp.max_factor==n) printf("Prime\n");
        else cout<<rhp.max_factor<<'\n';
    }
}
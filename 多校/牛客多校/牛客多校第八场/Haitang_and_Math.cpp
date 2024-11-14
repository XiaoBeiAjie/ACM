#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll ans = 0;
bool check(ll x, ll m)
{
	int sum = 0;
	if(x <= m) return false;
	while(x)
	{
		sum += (x % 10);
		x /= 10;
	}
	if(sum == m) return true;
	return false;
}
void dfs(vector<ll>& a, vector<ll>& an, int pos, ll sum, ll m)
{
	if(pos == a.size())
	{
		if(check(sum, m))
			ans++;
		return ;
	}
	ll tmp = 1;
	for(int i = 0; i <= an[pos]; i++)
	{
		dfs(a, an , pos + 1, sum * tmp, m);
		tmp *= a[pos];
	}
}
void solve() {
	ll n; cin >> n;ans=0;
	for (int i = 1; i <= 108; i ++ ) {
		ll tmp = n - i;//
        if(tmp <= 1) 
		{
			cout << ans << '\n';
			return;
		}
        vector<ll> a;//fac
		vector<ll> an;//cnt
        while(1)
        {
            srand((unsigned)time(NULL));
            Rhpr rhp(tmp);rhp.fac(tmp);
            //cout<<tmp<<' '<<rhp.max_factor<<'\n';
            if(tmp%rhp.max_factor) continue;
            if(rhp.max_factor==tmp) 
            {
                a.push_back(rhp.max_factor);
                break;
            }
            else 
            {
                a.push_back(rhp.max_factor);
                tmp/=rhp.max_factor;
            }
        }
        sort(a.begin(),a.end());
        vector<ll> b;
        int ij=0;
        while(ij<(int)a.size())
        {
            int ji=ij+1,g=1;
            while(ji<(int)a.size()&&a[ji]==a[ij]) ++g,++ji;
            b.push_back(a[ij]);an.push_back(g);
            ij=ji;
        }
		dfs(b, an, 0, 1, i);
	}
    cout<<ans<<'\n';
}

int main (void) {
    //freopen("std.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int T; cin >> T;
	while (T -- ) solve();
	return 0;
}
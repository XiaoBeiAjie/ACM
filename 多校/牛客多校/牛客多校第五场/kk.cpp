#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[10005];
int n;
//ll s[10005];
unordered_map<ll,ll>mp;
ll solve(ll x,ll y,ll ln,ll rn)
{//cout<<"??"<<x<<" "<<y<<" "<<ln<<" "<<rn<<" "<<endl;
    if(x==y)
    {
        return (ln-rn)*a[x];
    }
    if(x>y)return -2e15;
    ll hs=x*1005+y+(ln-rn)*10000000;
    if(mp.count(hs))return mp[hs];
    ll l=a[x]+1,r=a[y];
    ll ans=2e15;
    while(l<=r)
    //for(ll m=l;m<=r;m++)
    {
        cerr << "<<" << x << " " << y << " " << l << " " << r << "\n";
        ll m=l+r>>1;
        int p=lower_bound(a+1,a+1+n,m)-a;
        //cout<<"???"<<m<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<p<<endl;
       cerr << p << "!!!\n";
        // if(a[p]==m)
        // {//cout<<"ok"<<endl;
        //     ll lans=solve(x,p-1,ln,rn+1)+m;
        //     ll rans=solve(p+1,y,ln+1,rn)-m;
        //     if(lans>rans)r=m-1;
        //     else l=m+1;
        //     ans=min(ans,max(lans,rans));
        // }
        // else
        {
            ll lans=solve(x,p-1,ln,rn+1)+m;
            ll rans=solve(p,y,ln+1,rn)-m;
            if(lans>rans)r=m-1;
            else l=m+1;
            ans=min(ans,max(lans,rans));
        }
        //cerr<<"<<" << x << " " << y << " " <<l<<" "<<r<<" "<<m<<endl;
    }//cout<<"??"<<x<<" "<<y<<" "<<ln<<" "<<rn<<" "<<ans<<endl;
    mp[hs]=ans;
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        //a[i]=(ll)rand()*9187+3;
        cin>>a[i];
        //s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    cout<<solve(1,n,0,0)<<endl;
    return 0;
}
/*
*/

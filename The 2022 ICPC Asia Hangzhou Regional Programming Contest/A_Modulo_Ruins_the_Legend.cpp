#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        //cout<<GCD<<'*'<<'\n';
        if(c%GCD) return -1;
        y1=y1*(c/GCD)%(b/GCD);
        x+=LCM*y1;
        LCM*=b/GCD;
        x=(x%LCM+LCM)%LCM;
    }
    return x;
}
void solve() {
    ll n,m;cin>>n>>m;
    ll sum=0;
    for(int i=0,x;i<n;++i) cin>>x,sum+=x;
    ll a=n,b=1ll*n*(n+1)/2;
    ll gd=__gcd(a,b);
    //cout<<gd<<'\n';
    sum%=m;
    ll ans=sum%__gcd(gd,m);
    ll k;
    vector<ll> aa(2),bb(2);
    aa[0]=m;bb[0]=(m-sum+ans);
    aa[1]=gd;bb[1]=0;
    k=(excrt(bb,aa))/gd;
    cout<<ans<<'\n';
    //cout<<k<<'\n';
    ll x0,y0;
    exgcd(a,b,x0,y0);
    //cout<<x0<<' '<<y0<<'*'<<'\n';
    x0*=k;y0*=k;

    x0%=m;y0%=m;
    x0*=a;x0%=m;
    y0*=b;y0%=m;
    if(x0<0) x0+=m;
    if(y0<0) y0+=m;
    //cout<<x0<<' '<<y0<<'*'<<'\n';
    aa[0]=m;bb[0]=x0;
    aa[1]=a;bb[1]=0;
    ll t=excrt(bb,aa)/a;
    t%=m;
    cout<<t<<' ';
    aa[0]=m;bb[0]=y0;
    aa[1]=b;bb[1]=0;
    ll tt=excrt(bb,aa)/b;
    tt%=m;
    cout<<tt<<'\n';
    //cout<<'*'<<sum<<'\n';
//cout<<(sum+a*t%m+b*tt%m)%m<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    return 0;
}
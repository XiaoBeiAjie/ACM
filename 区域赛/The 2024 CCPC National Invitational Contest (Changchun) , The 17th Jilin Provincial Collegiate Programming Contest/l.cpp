#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

int T;

void solve() {
    ll k,x,y;cin>>k>>x>>y;
    ll ans=0;
    if(k==1) return cout<<x+y<<'\n',void();
    ll cnt=y/(k/2);
    if(k&1)
    {
        if(x>=cnt) 
        {
            ans+=cnt,x-=cnt;
            y-=k/2*cnt;
            if(y&&x>=k-y*2) ++ans,x-=k-y*2;
            ans+=x/k;
        }
        else
        {
            ans+=x;
            y-=k/2*x;x=0;
            ans+=y/(k/2+1);
        }
    }
    else
    {
        ans+=cnt;
        y-=k/2*cnt;
        if(y&&x>=k-y*2) ++ans,x-=k-y*2;
        ans+=x/k;
    }
    cout<<ans<<'\n';

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
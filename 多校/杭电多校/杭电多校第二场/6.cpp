#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<vector<int>> nex(n+1);
    for(int i=1,x,y;i<n;++i) cin>>x>>y,nex[x].push_back(y),nex[y].push_back(x);
    vector<ll> f(n+1,0);
    for(int i=1;i<=n;++i)
    {
        ll x;cin>>x;
        x=1ll*360360/x*15;
        f[i]=x;
    }
    auto dfs=[&](auto self,int x,int fa)->void
    {
        ll mx=0;
        for(auto &it:nex[x])
        {
            if(it==fa) continue;
            self(self,it,x);
            mx=max(mx,f[it]);
        }
        f[x]+=mx;
    };
    dfs(dfs,1,-1);
    ll gcd=__gcd(f[1],(ll)360360);
    cout<<f[1]/gcd<<'/'<<360360/gcd<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
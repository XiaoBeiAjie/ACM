#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1e9+7;
typedef long long ll;
#define int long long
ll dis[N];
ll val[N];
ll n , m;
ll dep[N];
vector<int > e[N];
void dfs(int u , int father , ll d)
{
    dep[u] = dep[father] + 1;
    dis[u] = (d + val[u]);
    for(int i = 0; i < e[u].size(); i++)
    {
        if(e[u][i] != father)
            dfs(e[u][i], u, dis[u]);
    }
}
void dfs1(int u,int father,ll d)
{
    dis[u] = (d + val[u]);
    while(dis[u]<0);
    for(int i = 0; i < e[u].size(); i++)
    {
        if(e[u][i] != father)
            dfs(e[u][i], u, dis[u]);
    }
}
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll qmi1(ll a,ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
// val[i] = (qmi(2, m) + (cnt - 2) * ((qmi(2, m) - 1) % mod + mod) % mod) % mod;
void solve() {
    cin >> n  >> m;
    //m=qmi(2,m);
    int x , y;
    for(int i = 1 ; i <= n ; i++)
        e[i].clear();
    for(int i = 0 ; i < n - 1; i ++)
    {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(n==1) return cout<<1<<'\n',void();
    ll tjj=9e18/(n*n);
    int cntjj=0;
    while(tjj>1) tjj/=2,++cntjj;
    if(m>cntjj)
    {
        //while(1);
        for (int i = 1; i <= n; i ++ ) {
            ll cnt = e[i].size();
                val[i] = cnt;
        }
        dfs(1, 0, 0);
        int s = 1;
        vector<int> fg;
        for(int i = 1 ; i <= n ; i++)
        {
            if(dis[s] == dis[i]) fg.push_back(i);
            else if(dis[s]<dis[i]) fg.clear(),fg.push_back(i),s=i;
        }
        ll mindep=2e9,ss=s;
        for(auto &it:fg)
        {
            s=it;
            dfs(s, 0ll, 0ll);
            int t = 1;
            for(int i = 1; i <= n ; i++)
            {
                if(dis[i] > dis[t]) t = i;
                else if(dis[i]==dis[t]&&dep[t]>dep[i]) t=i;
            }
            //dis[t]-=dep[t];dis[t]+=mod;dis[t]%=mod;
            //cout<<dep[t]<<'\n';
            if(mindep==2e9||dep[mindep]>dep[t]) mindep=t,ss=s;
            
        }
        dfs(ss, 0ll, 0ll);
        ll t=mindep;dis[t]-=dep[t];dis[t]+=mod;dis[t]%=mod;
        //cout<<dep[t]<<'\n';
        cout << ((dis[t] * (qmi(2ll,m)-1ll) % mod +dep[t]) % mod + mod) % mod << '\n';
        
        
        //cout << s << " " << t << '\n';
        // cout << dep[t] << endl;
        //cout<<dis[t]<<'\n';
        
        //cerr << "!!" << (m + 1) * dis[t] - m - 2 << "\n";
    }
    else
    {
        //while(1);
        for (int i = 1ll; i <= n; i ++ ) {
            ll cnt = e[i].size();
                val[i] = (qmi1(2ll, m) + (cnt - 2ll) * ((qmi1(2ll, m) - 1) ));
          while(val[i]<0);
        }
        dfs1(1ll, 0ll, 0ll);
        int s = 1;
        for(int i = 1 ; i <= n ; i++)
            if(dis[s] < dis[i]) s = i;
        dfs1(s, 0ll, 0ll);
        int t = 1;
        for(int i = 1ll; i <= n ; i++)
            if(dis[i] > dis[t]) t = i;
        cout<<dis[t]%mod<<'\n';
    }

}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
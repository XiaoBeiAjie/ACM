#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
const int mod=998244353;
void solve() {
    int n,s;cin>>n;
    vector<int> a(n+1);
    vector<int> f(n);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];f[a[i]]=i;
        if(!a[i]) s=i;
    }
    vector<vector<int>> e(n+1);
    for(int i=1,x,y;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    //cout<<'y';
    vector<ll> dp(n+1,0);
    vector<int> fa(n+1),par(n+1,0);iota(fa.begin(),fa.end(),0);
    auto find=[&](auto self,int x)->int
    {
        return x==fa[x]?x:fa[x]=self(self,fa[x]);
    };
    ll ans=0;
    auto dfs=[&](auto self,int x,int pa)->void
    {
        ll ss=1;
        for(auto &it:e[x])
        {
            if(it==pa) continue;
            par[it]=x;
            self(self,it,x);
            ss*=dp[it]+1;
            ss%=mod;
        }
        dp[x]=ss;
    };
    auto ksm=[&](ll x,ll t)->ll
    {
        ll res=1;
        while(t)
        {
            if(t&1) res=res*x%mod;
            x=x*x%mod;
            t>>=1;
        }
        return res;
    };
    dfs(dfs,s,-1);
    ans=dp[s];
    ll cur=dp[s];
    vector<bool> vis(n+1,0);//vis[s]=1;
    for(auto &it:e[s]) vis[it]=1;
    //set<int> li;
    //for(int i=1;i<=n;++i) if(vis[i]) li.insert(i);
    for(int i=1;i<n;++i)
    {
        int j=find(find,f[i]);
        if(j==s) 
        {
            ans+=cur;
            continue;
        }
        vector<int> tt;
        while(j!=s)
        {
            if(vis[j]) 
            {
                vis[j]=false;//li.erase(j);           
                cur*=ksm(dp[j]+1,mod-2),cur%=mod;
            }
            tt.push_back(j);
            j=fa[j]=find(find,par[j]);
        }
        for(auto &it:tt)
        {
            for(auto &it1:e[it])
            {
                if(find(find,it1)!=s&&!vis[it1]) 
                {
                    vis[it1]=true;//li.insert(it1);
                    cur*=dp[it1]+1;cur%=mod;
                }
            }
        }
        ans+=cur;ans%=mod;
        //for(auto &it:li) cout<<it<<' ';
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    //freopen("std.in","r",stdin);freopen("std.out","w",stdout);
    auto solve=[&]()->void
    {
        int n;cin>>n;
        vector<ll> a(n+1);
        ll sum=0,ans=0;
        for(int i=1;i<=n;++i) cin>>a[i],sum+=a[i];
        vector<array<ll,2>> f(n+1,{0,0});
        vector<array<ll,3>> g(n+1,{0,0,0});
        vector<vector<int>> nex(n+1);
        for(int i=1,x,y;i<n;++i) 
        {
            cin>>x>>y; 
            nex[x].push_back(y);
            nex[y].push_back(x);
        }
        auto dfs=[&](auto self,int x,int pre)->void
        {
            vector<array<ll,2>> sb;
            for(auto &it:nex[x])
            {
                if(it==pre) continue;
                self(self,it,x);
                f[x][0]+=max(f[it][1],f[it][0]);
                f[x][1]+=f[it][0];
                g[x][0]+=max(max(g[it][1],g[it][0]),g[it][2]);
                g[x][1]+=g[it][0];
                sb.push_back({g[it][0],g[it][1]});
                g[x][2]+=g[it][0];
            }
            f[x][1]+=a[x];
            g[x][1]+=a[x];
            g[x][2]+=a[x];
            ll mt=0;
            for(auto [xx,yy]:sb)
            {
                mt=max(mt,yy-xx);
            }
            g[x][2]+=mt;
            
        };
        dfs(dfs,1,-1);
        ans=sum*3-max(f[1][1],f[1][0])-max(g[1][0],max(g[1][1],g[1][2]));
        for(int i=1;i<=n;++i) f[i]={0,0};
        auto dfs1=[&](auto self,int x,int pre)->void
        {
            for(auto &it:nex[x])
            {
                if(it==pre) continue;
                self(self,it,x);
                f[x][0]+=f[it][1];
                f[x][1]+=f[it][0];
            }
            f[x][1]+=a[x];
        };
        dfs1(dfs1,1,-1);
        ans=min(ans,sum*2-max(f[1][0],f[1][1]));
        cout<<ans<<'\n';
 
    };
    int T=1;
    cin>>T;
    while(T--) solve();
	return 0;
}
/*
**Tashkent won't resist.
**Please be gentle...
1
5
1 1 100 100 100
1 2
1 3
2 4
2 5
*/
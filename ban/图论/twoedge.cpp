#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge
{
    int to,id;
    operator int()const{return to;}
};
struct LowLink
{
    int n;
    vector<vector<Edge>> g;
    vector<int> in,out,low;
    int ts;
    LowLink(const vector<vector<Edge>>&g):n(int(g.size())-1),g(g) 
    {
        ts=0;low.assign(n+1,0);
        in.assign(n+1,0);out.assign(n+1,0);
        for(int i=1;i<=n;++i) if(!in[i]) tarjan(i,-1);
        id.assign(n+1,0);cnt=0;
        for(int i=1;i<=n;++i) if(!id[i]) dfs(i,-1);
        group.resize(cnt+1);
        for(int i=1;i<=n;++i) group[id[i]].push_back(i);
    }
    void tarjan(int u,int from)
    {
        in[u]=low[u]=++ts;
        for(auto j:g[u])
        {
            if(!in[j]) tarjan(j,j.id),low[u]=min(low[u],low[j]);
            else if(j.id!=from) low[u]=min(low[u],in[j]);
        }
        out[u]=ts;
    }
    int cnt;
    vector<vector<int>> group;
    vector<int> id;
    void dfs(int u,int fa)
    {
        if (fa!=-1&&low[u]<=in[fa]) id[u]=id[fa];
        else id[u]=++cnt;
        for(auto j:g[u]) if(!id[j]) dfs(j,u);
    }
    void getans()//输出边双连通分量
    {
        vector<vector<int>> ng(cnt+1);
        for(int i=1;i<=n;++i)
        {
            for(auto [j,id1]:g[i])
            {
                if(id[i]!=id[j])
                {
                    ng[id[i]].push_back(id[j]);
                    cout<<i<<' '<<j<<'\n';
                }
            }
        }
    }
};
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<Edge>>g(n+1);
    for(int i=0,a,b;i<m;++i)
    {
        cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    LowLink lk(g);
    lk.getans();
}
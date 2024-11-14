#include <bits/stdc++.h>
using namespace std;
pair<vector<int>,vector<int>> 
    remaketre(int n,vector<array<int,3>>edges,
        function<bool(array<int,3>,array<int,3>)>comp=less<>())
{
    vector<int> p(2*n);
    for(int i=1;i<2*n;i++) p[i]=i;
    function<int(int)> find=[&](int x){if(x!=p[x])p[x]=find(p[x]);return p[x];};
    int cnt=n;
    sort(edges.begin(),edges.end(),comp);
    vector<int> value(n+1,0),parent(2*n,0);
    for(auto [weight,from,to]:edges)
    {
        from=find(from);
        to=find(to);
        if(from==to) continue;
        p[from]=++cnt;
        p[to]=cnt;
        value.push_back(weight);
        parent[from]=cnt;
        parent[to]=cnt;
    }
    parent.resize(value.size());
    return {value,parent};
}
struct LCA
{
    LCA(int n,vector<int>& parent):parent(parent),depth(n+1),pa(n+1)
    {
        for(int i=1;i<=n;++i)
        {
            if(this->parent[i]<=0) this->parent[i]=i;
            pa[i][0]=this->parent[i];
        }
        for(int i=1;i<20;++i)
        {
            for(int j=1;j<=n;j++)
            {
                pa[j][i]=pa[pa[j][i-1]][i-1];
            }
        }
        function<int(int)> get_depth=[&](int now)
        {
            if(now<=0||now>n) return 0;
            if(depth[now]) return depth[now];
            if(parent[now]<=0||parent[now]==now) return depth[now]=1;
            return depth[now]=get_depth(parent[now])+1;
        };
        for(int i=1;i<=n;++i) depth[i]=get_depth(i);
    }
    int lca(int u,int v) 
    {
        if(pa[u][19]!=pa[v][19]) return -1;
        if(depth[u]<depth[v]) swap(u,v);
        for(int i=19;depth[u]>depth[v];--i)
        {
            if(depth[pa[u][i]]>=depth[v])u=pa[u][i];
        }
        if(u==v) return u;
        for(int i=19;i>=0;--i)
        {
            if(pa[u][i]!=pa[v][i])u=pa[u][i],v=pa[v][i];
        }
        return pa[u][0];
    }
private:
    vector<int> parent,depth;
    vector<array<int,20>> pa;
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    for(int i=1,x,y,w;i<=m;++i)
    {
        cin>>x>>y>>w;
        edges.push_back({w,x,y});
    }
    auto [value,parent]=remaketre(n,edges);
    vector<vector<int>> nex;
    int s=value.size()-1;nex.resize(s+1);
    for(int i=1;i<=s;++i) 
    {
        if(parent[i]) nex[parent[i]].push_back(i);//新树,s为根
    }
    LCA t((int)value.size()-1,parent);
    int q;cin>>q;
    for(int i=0,x,y,idx;i<q;++i)
    {
        cin>>x>>y;idx=t.lca(x,y);
        if(idx==-1) cout<<-1<<'\n';//不连通
        else cout<<value[idx]<<'\n';//路径最大边权
    }
}
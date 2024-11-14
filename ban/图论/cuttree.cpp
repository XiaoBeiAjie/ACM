#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to,ne;
    edge(int x=0,int y=0):to(x),ne(y){}
};
struct Cuttree
{
    int tot;
    vector<edge> e;
    vector<int> head,dep,siz,son,top,fa;
    Cuttree(int sz)
    {
        head.resize(sz+1,0);fa.resize(sz+1,0);
        dep.resize(sz+1,0);siz.resize(sz+1,0);
        son.resize(sz+1,0);top.resize(sz+1,0);
        tot=0;e.resize(2*sz+1,edge());
    }
    void add(int x,int y)
    {
        e[++tot].to=y;
        e[tot].ne=head[x];
        head[x]=tot;
    }
    void dfs1(int x)
    {
        siz[x]=1;
        dep[x]=dep[fa[x]]+1;
        for(int i=head[x];i;i=e[i].ne)
        {
            int dd=e[i].to;
            if(dd==fa[x])continue;
            fa[dd]=x;
            dfs1(dd);
            siz[x]+=siz[dd];
            if(!son[x]||siz[son[x]]<siz[dd])son[x]=dd;
        }
    }
    void dfs2(int x,int tv)
    {
        top[x]=tv;
        if(son[x])dfs2(son[x],tv);
        for(int i=head[x];i;i=e[i].ne)
        {
            int dd=e[i].to;
            if(dd==fa[x]||dd==son[x]) continue;
            dfs2(dd,dd);
        }
    }
    int lca(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dep[top[x]]>=dep[top[y]])x=fa[top[x]];
            else y=fa[top[y]];
        }
        return dep[x]<dep[y]?x:y;
    }
};
int main()
{
    int n,m,s;cin>>n>>m>>s;//s为根
    Cuttree cte(n);
    for(int i=1,x,y;i<n;++i)cin>>x>>y,cte.add(x,y),cte.add(y,x);
    cte.dfs1(s);cte.dfs2(s,s);
    for(int i=1,x,y;i<=m;++i) cin>>x>>y,cout<<cte.lca(x,y)<<'\n';
}
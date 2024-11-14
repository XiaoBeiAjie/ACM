#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int fa[maxn],ans[maxn],pre[maxn];
array<int,3> que[maxn];
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
        head.resize(sz+1);fa.resize(sz+1);
        dep.resize(sz+1);siz.resize(sz+1);
        son.resize(sz+1);top.resize(sz+1);
        tot=0;e.resize(2*sz+1);
        for(int i=0;i<sz+1;++i) head[i]=fa[i]=dep[i]=siz[i]=son[i]=top[i]=0;
        for(int i=0;i<2*sz+1;++i) e[i]=edge();
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
void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;++i) ans[i]=pre[i]=0,fa[i]=i;
    auto find=[&](auto self,int x)->int
    {
        return x==fa[x]?x:fa[x]=self(self,fa[x]);
    };
    Cuttree cte(n);
    vector<vector<int>> nex(n+1);
    for(int i=0,tx,ty,z;i<n-1;++i)
    {
        cin>>tx>>ty>>z;
        que[i]={tx,ty,z};
        cte.add(tx,ty);
        pre[ty]=tx;
        nex[tx].push_back(ty);
    }
    


    int s;
    for(int i=1;i<=n;++i) if(pre[i]==0) s=i;
    

    cte.dfs1(s);cte.dfs2(s,s);
    


    auto dist=[&](int x,int y)->int
    {
        int z=cte.lca(x,y);
        return cte.dep[x]+cte.dep[y]-2*cte.dep[z];
    };
    for(int i=0;i<n-1;++i)
    {
        auto [tx,ty,z]=que[i];
        int fx=find(find,tx);
        fa[tx]=fa[ty]=fx;
        //cout<<fx<<' '<<ty<<'\n';
        ans[fx]=max(ans[fx],dist(fx,ty)+ans[ty]);
        /*
        int x=tx,j=1;
        while(x)
        {
            ans[x]=max(ans[ty]+j,ans[x]);
            ++j;x=pre[x];
        }
        */
        cout<<ans[z]<<" \n"[i==n-2];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
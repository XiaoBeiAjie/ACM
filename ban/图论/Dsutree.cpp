#include <bits/stdc++.h>
using namespace std;
struct Dstree
{
    vector<vector<int>> g;
    vector<int> sz,big,col,L,R,Node,cnt,ans,dep;
    int totcol,totdfn;
    Dstree(int siz,int s=1)
    {
        g.resize(siz+1);sz.resize(siz+1,0);
        big.resize(siz+1,0);col.resize(siz+1,0);
        L.resize(siz+1,0);R.resize(siz+1,0);
        Node.resize(siz+1,0);cnt.resize(siz+1,0);
        ans.resize(siz+1,0);totcol=totdfn=0;
        dep.resize(siz+1,0);dep[s]=1;
    }
    void add(int u) 
    {
        if(cnt[col[u]]==0) ++totcol;
        ++cnt[col[u]];
    }
    void del(int u) 
    {
        --cnt[col[u]];
        if(cnt[col[u]]==0) --totcol;
    }
    int getAns() {return totcol;}
    void dfs0(int u,int p) 
    {
        L[u]=++totdfn;
        Node[totdfn]=u;
        sz[u]=1;
        for(int v:g[u])
        {
            if(v!=p) 
            {
                dfs0(v,u);
                sz[u]+=sz[v];
                if(!big[u]||sz[big[u]]<sz[v]) big[u]=v;
            }
        }
        R[u]=totdfn;
    }
    void dfs1(int u,int p,bool keep) 
    {
        for(int v:g[u])if(v!=p&&v!=big[u]) dfs1(v,u,false);
        if(big[u]) dfs1(big[u],u,true);
        for(int v:g[u])
        {
            if(v!=p&&v!=big[u]) 
            {
                for(int i=L[v];i<=R[v];++i) add(Node[i]);
            }
        }
        add(u);ans[u]=getAns();
        if(keep==false)for(int i=L[u];i<=R[u];++i) del(Node[i]);
    }
};
int main() 
{
    int n;cin>>n;Dstree dst(n);
    for(int i=1;i<=n;++i) cin>>dst.col[i];
    for(int i=1,u,v;i<n;++i) 
    {
        cin>>u>>v;
        dst.g[u].push_back(v);
        dst.g[v].push_back(u);
    }
    dst.dfs0(1,0);dst.dfs1(1,0,false);
    cin>>n;
    for(int i=1,x;i<=n;++i) cin>>x,cout<<dst.ans[x]<<'\n';//x子树颜色数量
}
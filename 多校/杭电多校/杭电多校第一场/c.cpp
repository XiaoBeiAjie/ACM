#include <bits/stdc++.h>
#define OpenFile freopen("std.in","r",stdin);freopen("std.out","w",stdout);
#define FastIO ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
#define End return 0;
using namespace std;
using ll=long long;
ll ans;
vector<ll> sum;
struct Dstree
{
    vector<vector<int>> g;
    vector<int> sz,big,col,L,R,Node,cnt,dep;
    int totcol,totdfn,k;
    ll sum2,sum1;
    map<ll,int> se2;
    map<ll,ll> faa;
    Dstree(int siz,int s=1)
    {
        g.resize(siz+1);sz.resize(siz+1,0);
        big.resize(siz+1,0);col.resize(siz+1,0);
        L.resize(siz+1,0);R.resize(siz+1,0);
        Node.resize(siz+1,0);cnt.resize(siz+1,0);
        totcol=totdfn=0;
        dep.resize(siz+1,0);dep[s]=1;sum1=sum2=0;
    }
    void add(int u) 
    {
        sum1+=col[u];
        sum2+=1ll*col[u]*col[u];
        se2[1ll*col[u]*col[u]]++;
    }
    void del(int u) 
    {
        sum1-=col[u];
        if(!faa[1ll*col[u]*col[u]])
        sum2-=1ll*col[u]*col[u],se2[1ll*col[u]*col[u]]--;
        else
        {
            ll zz=faa[1ll*col[u]*col[u]];
            sum2-=zz;se2[zz]--;
            faa[1ll*col[u]*col[u]]=0;
        }

    }
    int getAns() 
    {
        return totcol;
    }
    void dfs0(int u,int p) 
    {
        L[u]=++totdfn;
        Node[totdfn]=u;
        sz[u]=1;
        for(int v:g[u])
        {
            if(v!=p) 
            {
                dep[v]=dep[u]+1;
                dfs0(v,u);
                sz[u]+=sz[v];
                if(!big[u]||sz[big[u]]<sz[v]) big[u]=v;
            }
        }
        R[u]=totdfn;
    }
    void dfs1(int u,int p,bool keep) 
    {
        for(int v:g[u])
        {
            if(v!=p&&v!=big[u]) dfs1(v,u,false);
        }
        if(big[u]) dfs1(big[u],u,true);
        for(int v:g[u])
        {
            if(v!=p&&v!=big[u]) 
            {
                for(int i=L[v];i<=R[v];++i) 
                {
                    add(Node[i]);
                }
            }
        } 
        add(u);
        //ll sum=0;
        while(se2.begin()->first<(1ll*col[u]*col[u]))
        {
            se2[1ll*col[u]*col[u]]+=se2.begin()->second;
            sum2-=se2.begin()->first*se2.begin()->second;
            faa[se2.begin()->first]=1ll*col[u]*col[u];
            sum2+=1ll*col[u]*col[u]*se2.begin()->second;
            se2.erase(se2.begin());
        }
        //add(u);
        sum[u]+=sum2-sum1*col[u];
        //sum*=2;
        //cout<<u<<' '<<sum1<<' '<<sum2<<'\n';
        //cout<<u<<' '<<sum*2<<'\n';
        if(keep==false) 
        {
            for(int i=L[u];i<=R[u];++i) 
            {
                int j=Node[i];
                while(se2.begin()->first<(1ll*col[j]*col[j]))
                {
                    se2[1ll*col[j]*col[j]]+=se2.begin()->second;
                    sum2-=se2.begin()->first*se2.begin()->second;
                    faa[se2.begin()->first]=1ll*col[j]*col[j];
                    sum2+=1ll*col[j]*col[j]*se2.begin()->second;
                    se2.erase(se2.begin());
                }
                sum[u]+=sum2-sum1*col[j];
                del(Node[i]);
            }
        }
        //ans^=sum[u]*2;
    }
};
void solve()
{
    int n;cin>>n;Dstree dst(n);
    sum.resize(n+1);
    for (int i=1,u,v;i<n;++i) 
    {
        cin>>u>>v;
        dst.g[u].push_back(v);
        dst.g[v].push_back(u);
    }
    for(int i=1;i<=n;++i) cin>>dst.col[i];
    dst.dfs0(1,0);
    dst.dfs1(1,0,false);
    for(int i=1;i<=n;++i) 
    {
        ans^=sum[i];
        cout<<i<<' '<<sum[i]<<'\n';
    }
    cout<<ans<<'\n';
}
int main()
{
    //OpenFile
    FastIO
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;++i)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    End
}
/*
4 ;4
3 ;
2 4 ;
1 ;1 2
*/
/*
4 ;4
3 ;
2 4 ;
1 ;1 2 3 4
*/
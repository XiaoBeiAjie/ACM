#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=1e9+7;
int n,m;
#define l(u) ch[u][0]
#define r(u) ch[u][1]
struct HDLT {
    static const int N=5e3+10;
    int blocks;
    ll f(int x,int y) {return (ll)x*M+y;}
    struct LCT {
        struct List {
            int hd[N],pre[N],nxt[N];
            void init(int n) {for(int u=1; u<=n; ++u)hd[u]=0;}
            void link(int u,int v) {
                if(!hd[u])hd[u]=pre[v]=nxt[v]=v;
                else {
                    int x=hd[u],y=pre[x];
                    pre[x]=nxt[y]=v;
                    pre[v]=y,nxt[v]=x;
                }
            }
            void cut(int u,int v) {
                if(nxt[v]==v)hd[u]=0;
                else {
                    if(hd[u]==v)hd[u]=nxt[v];
                    pre[nxt[v]]=pre[v],nxt[pre[v]]=nxt[v];
                }
            }
            bool empty(int u) {return hd[u]==0;}
            int first(int u) {return hd[u];}
        } chv[2];
        unordered_set<int> G[N][2];
        void linkv(int u,int v) {
            if(!u||!v)return;
            sizv[u]+=siz[v];
            for(int i=0; i<2; ++i)if(tag[v][i])chv[i].link(u,v);
        }
        void cutv(int u,int v) {
            if(!u||!v)return;
            sizv[u]-=siz[v];
            for(int i=0; i<2; ++i)if(tag[v][i])chv[i].cut(u,v);
        }
        int fa[N],ch[N][2],flp[N],sta[N],tp,siz[N],sizv[N],tag[N][2];
        void rev(int u) {flp[u]^=1,swap(l(u),r(u));}
        void pu(int u) {
            if(!u)return;
            for(int i=0; i<2; ++i)tag[u][i]=tag[l(u)][i]|tag[r(u)][i]|!G[u][i].empty()|!chv[i].empty(u);
            siz[u]=siz[l(u)]+siz[r(u)]+1+sizv[u];
        }
        void pd(int u) {if(flp[u])rev(l(u)),rev(r(u)),flp[u]=0;}
        int sf(int u) {return u==r(fa[u]);}
        bool isrt(int u) {return u!=l(fa[u])&&u!=r(fa[u]);}
        void rot(int u) {
            int v=fa[u],f=sf(u);
            bool flag=isrt(v);
            if(!flag)ch[fa[v]][sf(v)]=u;
            else if(fa[v])cutv(fa[v],v);
            ch[v][f]=ch[u][f^1],fa[ch[v][f]]=v;
            fa[u]=fa[v],ch[u][f^1]=v,fa[v]=u,pu(v);
            if(flag)pu(u),linkv(fa[u],u);
        }
        void splay(int u) {
            sta[tp=0]=u;
            for(int v=u; !isrt(v); v=fa[v])sta[++tp]=fa[v];
            for(; ~tp; pd(sta[tp--]));
            for(; !isrt(u); rot(u))if(!isrt(fa[u])&&sf(fa[u])==sf(u))rot(fa[u]);
        }
        void access(int u) {
            int w=u;
            for(int v=0; u; u=fa[v=u])splay(u),linkv(u,r(u)),cutv(u,v),r(u)=v,pu(u);
            splay(w);
        }
        void makert(int u) {access(u),rev(u);}
        void join(int u,int v) {makert(u),access(v);}
        int findrt(int u) {access(u); for(; l(u); pd(u),u=l(u)); splay(u); return u;}
        void link(int u,int v) {
            makert(u);
            if(findrt(v)==u)return;
            fa[u]=v,linkv(v,u),pu(v),access(v);
        }
        void cut(int u,int v) {join(u,v); if(l(v)!=u||r(u))return; fa[u]=l(v)=0,pu(v);}
        int get(int u,int f) {
            access(u);
            if(!tag[u][f])return 0;
            while(G[u][f].empty()) {
                if(tag[l(u)][f])u=l(u);
                else if(tag[r(u)][f])u=r(u);
                else u=chv[f].first(u);
            }
            return u;
        }
        bool isconnected(int u,int v) {return findrt(u)==findrt(v);}
        void ins(int f,int u,int v) {
            if(G[u][f].size()==0)access(u);
            G[u][f].insert(v),pu(u);
            if(G[v][f].size()==0)access(v);
            G[v][f].insert(u),pu(v);
        }
        void del(int f,int u,int v) {
            if(G[u][f].size()==1)access(u);
            G[u][f].erase(v),pu(u);
            if(G[v][f].size()==1)access(v);
            G[v][f].erase(u),pu(v);
        }
        void init(int n) {
            for(int i=0; i<2; ++i) {
                chv[i].init(n);
                for(int u=1; u<=n; ++u)G[u][i].clear();
            }
            for(int u=1; u<=n; ++u)fa[u]=l(u)=r(u)=tag[u][0]=tag[u][1]=flp[u]=sizv[u]=0,siz[u]=1;
        }
    } F[20];
    unordered_map<ll,int> LV;
    void instree(int lv,int u,int v) {LV[f(u,v)]=LV[f(v,u)]=lv; F[lv].ins(0,u,v);}
    void insgraph(int lv,int u,int v) {LV[f(u,v)]=LV[f(v,u)]=lv; F[lv].ins(1,u,v);}
    void deltree(int lv,int u,int v) {F[lv].del(0,u,v);}
    void delgraph(int lv,int u,int v) {F[lv].del(1,u,v);}
    bool findreplace(int lv,int u,int v) {
        F[lv].access(u),F[lv].access(v);
        if(F[lv].siz[u]>F[lv].siz[v])swap(u,v);
        int t=u,replacev=0;
        while((u=F[lv].get(u,0))) {
            unordered_set<int>& G=F[lv].G[u][0];
            while(G.size()) {
                int v=*G.begin();
                deltree(lv,u,v),instree(lv+1,u,v),F[lv+1].link(u,v);
            }
        }
        u=t;
        while((u=F[lv].get(u,1))) {
            unordered_set<int>& G=F[lv].G[u][1];
            while(G.size()) {
                int v=*G.begin();
                if(F[lv].isconnected(u,v))delgraph(lv,u,v),insgraph(lv+1,u,v);
                else {
                    replacev=v,delgraph(lv,u,replacev),instree(lv,u,replacev);
                    for(int i=0; i<=lv; ++i)F[i].link(u,replacev);
                    break;
                }
            }
            if(replacev)return 1;
        }
        return 0;
    }
    int isconnected(int u,int v) {return F[0].isconnected(u,v);}
    int getblocksize(int u) {F[0].access(u); return F[0].siz[u];}
    void link(int u,int v) {
        if(!isconnected(u,v))F[0].link(u,v),instree(0,u,v),--blocks;
        else insgraph(0,u,v);
    }
    void cut(int u,int v) {
        int lv=LV[f(u,v)];
        if(F[lv].G[u][0].count(v)) {
            for(int i=0; i<=lv; ++i)F[i].cut(u,v);
            deltree(lv,u,v);
            ++blocks;
            for(int i=lv; i>=0; --i)if(findreplace(i,u,v)) {--blocks; break;}
        } else delgraph(lv,u,v);
    }
    void del(int u) {
        vector<int> vec;
        for(int t=0; t<2; ++t)
            for(int i=0; i<20; ++i)
                for(int v:F[i].G[u][t])
                    vec.push_back(v);
        for(int v:vec)cut(u,v);
        --blocks;
    }
    void init(int n) {
        for(int i=0; i<20; ++i)F[i].init(n);
        LV.clear(),blocks=n;
    }
} solver;
int main() {
	int k ; 
    scanf("%d%d%d",&n,&m,&k);
    solver.init(n);
    for( ; m--;) {
        int u,v;
        scanf("%d%d",&u,&v);
   		solver.link(u,v);
    }
    for(int i =1; i <=k ; ++ i ){
    	int u , v; scanf("%d%d",&u,&v);
    	int t=solver.isconnected(u,v);
        printf("%c\n",t?'1':'0');
	}
    return 0;
}

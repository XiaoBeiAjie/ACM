#include <bits/stdc++.h>
using namespace std;
struct Dsu
{
    vector<int> fa,rk;
    Dsu(int siz)
    {
        fa.resize(siz+1);
        rk.resize(siz+1,1);
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x){return x==fa[x]?x:(fa[x]=find(fa[x]));}
    void merge(int i,int j) 
    {
        int x=find(i),y=find(j);
        if(x==y) return;
        if(rk[x]<=rk[y]) fa[x]=y;
        else fa[y]=x;
        if(rk[x]==rk[y]) rk[y]++;
    }
};
int main()
{
    int n,m,p;cin>>n>>m>>p;
    Dsu dsu(n);
    for(int i=0,x,y;i<m;++i) cin>>x>>y,dsu.merge(x,y);
    for(int i=0,x,y;i<p;++i)
    {
        cin>>x>>y;
        if(dsu.find(x)==dsu.find(y)) cout<<"One Set"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int s,id;
    node(int aa=0,int bb=0):s(aa),id(bb){}
};
struct Treearr
{
    int n;
    vector<int> a,tree;
    vector<node> b;
    Treearr(int siz)
    {
        a.resize(siz+1);tree.resize(siz+1,0);
        b.resize(siz+1);n=siz;
    }
    int lowbit(int x){return x&(-x);}
    void add(int x,int d=1){while(x<n+1) tree[x]+=d,x+=lowbit(x);}
    int query(int x,int res=0)
    {
        while(x) res+=tree[x],x-=lowbit(x);
        return res;
    }
    void qsort()
    {
        sort(b.begin(),b.end(),[](node x,node y){return x.s==y.s?x.id<y.id:x.s<y.s;});
        int i=0;while(b[i].id==0) ++i;
        for(int j=i;j-i<n;++j) a[b[j].id]=j-i+1;
    }
};
int main()
{
    int n;cin>>n;Treearr tre(n);
    for(int i=1;i<=n;++i) cin>>tre.a[i],tre.b[i]=node(tre.a[i],i);
    tre.qsort();int ans=0;
    for(int i=1,t;i<=n;++i)
    {
        t=tre.query(n)-tre.query(tre.a[i]-1);
        ans+=t;tre.add(tre.a[i]);
    }
    cout<<ans<<'\n';//逆序对数量
}

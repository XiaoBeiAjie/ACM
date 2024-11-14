#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct tree
{
    vector<ll> sum;
    vector<int> lt,rt,root;
    int tot;
    tree(int sz)
    {
        sum.resize(32*sz+5);tot=0;
        lt.resize(32*sz+5);rt.resize(32*sz+5);
        root.resize(32*sz+5);
    }
    void pushup(int p){sum[p]=sum[lt[p]]+sum[rt[p]];}
    int build(int pl,int pr)
    {
        int tr=++tot;
        if(pl==pr) return cin>>sum[tr],tr;
        int mid=(pl+pr)>>1;
        lt[tr]=build(pl,mid);
        rt[tr]=build(mid+1,pr);
        pushup(tr);
        return tr;
    }
    int update(int pre,int pl,int pr,int pos,int k)
    {
        int tr=++tot;
        lt[tr]=lt[pre];rt[tr]=rt[pre];
        if(pl==pr) return sum[tr]=k,tr;
        int mid=(pl+pr)>>1;
        if(pos<=mid) lt[tr]=update(lt[tr],pl,mid,pos,k);
        else rt[tr]=update(rt[tr],mid+1,pr,pos,k);
        pushup(tr);
        return tr;
    }
    ll query(int p,int pl,int pr,int l,int r)
    {
        if(l<=pl&&r>=pr) return sum[p];
        int mid=(pl+pr)>>1;ll res=0;
        if(l<=mid) res+=query(lt[p],pl,mid,l,r);
        if(r>mid) res+=query(rt[p],mid+1,pr,l,r);
        return res;
    }
};
int main()
{
    int n,m;cin>>n>>m;
    tree tre(n);
    tre.root[0]=tre.build(1,n);
    for(int i=1,op,x,y;i<=m;++i)
    {
        cin>>op>>x;
        if(op) cin>>y;
        if(!op) tre.root[i]=tre.root[x];//回溯到第x次操作后
        else if(op==1) tre.root[i]=tre.update(tre.root[i-1],1,n,x,y);//a[x]=y
        else cout<<tre.query(tre.root[i]=tre.root[i-1],1,n,x,y)<<'\n';//a[x]-a[y]和
    }
}
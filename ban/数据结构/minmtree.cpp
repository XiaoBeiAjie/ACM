#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define ls tr<<1
#define rs tr<<1|1
struct tree
{
    vector<ll> sum,add;
    tree(int siz)
    {
        sum.resize(4*siz+5,-9e18);add.resize(4*siz+5,0);
    }
    void pushup(int tr){sum[tr]=min(sum[ls],sum[rs]);}
    void build(int tr,int l,int r)
    {
        int mid=(l+r)>>1;ll x;
        if(l==r) return cin>>x,sum[tr]=x,void();
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(tr);
    }
    void pushdown(int tr)
    {
        if(add[tr])
        {
            add[ls]=add[ls]+add[tr];
            add[rs]=add[rs]+add[tr];
            sum[ls]=sum[ls]+add[tr];
            sum[rs]=sum[rs]+add[tr];
            add[tr]=0;
        }
    }
    void update(int tr,ll x,int L,int R,int l,int r)
    {
        if(L>r||R<l) return;
        if(L<=l&&R>=r) return add[tr]=(add[tr]+x),sum[tr]=(sum[tr]+x),void();
        int mid=(l+r)>>1;
        pushdown(tr);
        if(R<=mid) update(ls,x,L,R,l,mid);
        else if(L>mid) update(rs,x,L,R,mid+1,r);
        else update(ls,x,L,mid,l,mid),update(rs,x,mid+1,R,mid+1,r);
        pushup(tr);
    }
    ll minm(int tr,int L,int R,int l,int r)
    {
        ll res=9e18;
        if(L>r||R<l) return res;
        if(L<=l&&R>=r) return sum[tr];
        int mid=(l+r)>>1;
        pushdown(tr);
        if(R<=mid) res=min(res,minm(ls,L,R,l,mid));
        else if(L>mid) res=min(res,minm(rs,L,R,mid+1,r));
        else res=min(res,min(minm(ls,L,R,l,mid),minm(rs,L,R,mid+1,r)));
        return res;
    }
};
int main()
{
    int n,q;cin>>n>>q;
    tree tre(n);tre.build(1,1,n);
    for(int i=0,l,r,k,x;i<q;++i)
    {
        cin>>x;
        if(x==1) cin>>l>>r>>k,tre.update(1,k,l,r,1,n);//区间+k
        else cin>>l>>r,cout<<tre.minm(1,l,r,1,n)<<'\n';//区间最值
    }
}
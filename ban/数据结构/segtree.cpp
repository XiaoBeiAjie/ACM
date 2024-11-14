#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define ls tr<<1
#define rs tr<<1|1
struct tree
{
    vector<ll> sum,add,mul;
    tree(int siz)
    {
        sum.resize(4*siz+5,0);mul.resize(4*siz+5,1);
        add.resize(4*siz+5,0);
    }
    void pushup(int tr) {sum[tr]=sum[ls]+sum[rs];}
    void build(int tr,int l,int r)
    {
        int mid=(l+r)>>1,x;
        if(l==r) return cin>>x,sum[tr]=x,void();
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(tr);
    }
    void pushdown(int tr,int llen,int rlen)
    {
        if(mul[tr]!=1) 
        {
            add[ls]=add[ls]*mul[tr];
            add[rs]=add[rs]*mul[tr];
            sum[ls]=sum[ls]*mul[tr];
            sum[rs]=sum[rs]*mul[tr];            
            mul[ls]=mul[ls]*mul[tr];
            mul[rs]=mul[rs]*mul[tr];
            mul[tr]=1;
        }
        if(add[tr])
        {
            add[ls]=add[ls]+add[tr];
            add[rs]=add[rs]+add[tr];
            sum[ls]=sum[ls]+add[tr]*llen;
            sum[rs]=sum[rs]+add[tr]*rlen;
            add[tr]=0;
        }
    }
    void update(int flag,int tr,int x,int L,int R,int l,int r)
    {
        if(L>r||R<l) return;
        if(L<=l&&R>=r) 
        {
            if(flag==2) add[tr]=add[tr]+x,sum[tr]=sum[tr]+x*(r-l+1);
            else mul[tr]=mul[tr]*x,sum[tr]=sum[tr]*x,add[tr]=add[tr]*x;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(tr,mid-l+1,r-mid);
        if(R<=mid) update(flag,ls,x,L,R,l,mid);
        else if(L>mid) update(flag,rs,x,L,R,mid+1,r);
        else update(flag,ls,x,L,mid,l,mid),update(flag,rs,x,mid+1,R,mid+1,r);
        pushup(tr);
    }
    int query(int tr,int L,int R,int l,int r)
    {
        if(L>r||R<l) return 0;
        if(L<=l&&R>=r) return sum[tr];
        int mid=(l+r)>>1;
        pushdown(tr,mid-l+1,r-mid);
        return query(ls,L,R,l,mid)+query(rs,L,R,mid+1,r);
    }
};
int main()
{
    int n,q;cin>>n>>q;
    tree seg(n);seg.build(1,1,n);
    for(int i=0,op,x,y,k;i<q;++i)
    {
        cin>>op>>x>>y;
        if(op<3) cin>>k;
        if(op==3) cout<<seg.query(1,x,y,1,n)<<'\n';//区间和
        else seg.update(op,1,k,x,y,1,n);//1为乘k,2为加k
    }
}
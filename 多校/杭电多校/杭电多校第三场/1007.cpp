#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define ls tr<<1
#define rs tr<<1|1
int n;
struct tree
{
    vector<ll> sum,add,sum1;//sum,区间最小;sum1,区间最大
    tree(int siz)
    {
        sum.resize(4*siz+50,-1e18);add.resize(4*siz+50,0);
        sum1.resize(4*siz+50,1e18);
    }
    void pushup(int tr)
    {
        sum[tr]=min(sum[ls],sum[rs]);
        sum1[tr]=max(sum1[ls],sum1[rs]);
    }
    void build(int tr,int l,int r)
    {
        int mid=(l+r)>>1;ll x;
        if(l==r) return cin>>x,sum1[tr]=sum[tr]=x,void();
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
            sum1[ls]=sum1[ls]+add[tr];
            sum1[rs]=sum1[rs]+add[tr];
            add[tr]=0;
        }
    }
    void update(int tr,ll x,int L,int R,int l,int r)
    {
        if(L>r||R<l) return;
        if(L<=l&&R>=r) return add[tr]=add[tr]+x,sum[tr]=sum[tr]+x,sum1[tr]=sum1[tr]+x,void();
        int mid=(l+r)>>1;
        pushdown(tr);
        if(R<=mid) update(ls,x,L,R,l,mid);
        else if(L>mid) update(rs,x,L,R,mid+1,r);
        else update(ls,x,L,R,l,mid),update(rs,x,L,R,mid+1,r);
        pushup(tr);
    }
    ll minm(int tr,int L,int R,int l,int r)
    {
        ll res=1e18;
        if(L>r||R<l) return res;
        if(L<=l&&R>=r) return sum[tr];
        int mid=(l+r)>>1;
        pushdown(tr);
        if(R<=mid) res=min(res,minm(ls,L,R,l,mid));
        else if(L>mid) res=min(res,minm(rs,L,R,mid+1,r));
        else res=min(res,min(minm(ls,L,R,l,mid),minm(rs,L,R,mid+1,r)));
        return res;
    }
    ll maxm(int tr,int L,int R,int l,int r)
    {
        ll res=-1e18;
        if(L>r||R<l) return res;
        if(L<=l&&R>=r) return sum1[tr];
        int mid=(l+r)>>1;
        pushdown(tr);
        if(R<=mid) res=max(res,maxm(ls,L,R,l,mid));
        else if(L>mid) res=max(res,maxm(rs,L,R,mid+1,r));
        else res=max(res,max(maxm(ls,L,R,l,mid),maxm(rs,L,R,mid+1,r)));
        return res;
    }
    bool checkup(int tr,int L,int R,int l,int r)
    {
        if(L>r||R<l) return true;
        int mid=(l+r)>>1;
        if(mid>=L&&mid+1<=R)
        {
            //cout<<mid<<'*'<<'\n';
            if(maxm(1,L,mid,1,n)>=minm(1,mid+1,R,1,n)) return false;
        }
        //if(maxm(ls,L,mid,l,mid)>=minm(rs,mid+1,R,mid+1,r)) return false;
        if(L<=l&&R>=r) return true;
        pushdown(tr);
        if(R<=mid) return checkup(ls,L,R,l,mid);
        else if(L>mid) return checkup(rs,L,R,mid+1,r);
        else 
        {
            //cout<<L<<' '<<mid<<'\n';cout<<mid+1<<' '<<R<<'\n';
            if(checkup(ls,L,R,l,mid)&&checkup(rs,L,R,mid+1,r)) return true;
            else return false;
        }
    }
    bool checkdown(int tr,int L,int R,int l,int r)
    {
        if(L>r||R<l) return true;
        int mid=(l+r)>>1;
        if(mid>=L&&mid+1<=R)
        {
            //cout<<mid<<'*'<<'\n';
            if(minm(1,L,mid,1,n)<=maxm(1,mid+1,R,1,n)) return false;
        }
        //if(minm(ls,L,mid,l,mid)<=maxm(rs,mid+1,R,mid+1,r)) return false;
        if(L<=l&&R>=r) return true;
        pushdown(tr);
        if(R<=mid) return checkdown(ls,L,R,l,mid);
        else if(L>mid) return checkdown(rs,L,R,mid+1,r);
        else 
        {
            if(checkdown(ls,L,R,l,mid)&&checkdown(rs,L,R,mid+1,r)) return true;
            else return false;
        }
    }
    /*
    int find(int tr,int l,int r,int pos)
    {
        if(pos==l&&l==r) return sum1[tr];
        int mid=(l+r)>>1;
        pushdown(tr);
        if(pos<=mid) return find(ls,l,mid,pos);
        else return find(rs,mid+1,r,pos);
    }
    */
};
void solve() {
    cin>>n;
    tree tre(n);tre.build(1,1,n);
    int q;cin>>q;
    for(int i=0,l,r,k,x;i<q;++i)
    {
        cin>>x;
        if(x==1) cin>>l>>r>>k,tre.update(1,k,l,r,1,n);//区间+k
        else if(x==2) 
        {
            cin>>l>>r;
            if(tre.minm(1,l,r,1,n)==tre.maxm(1,l,r,1,n)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(x==3)
        {
            cin>>l>>r;
            if(tre.checkup(1,l,r,1,n)) cout<<1<<'\n';
            else cout<<0<<'\n' ;
        }
        else if(x==4)
        {
            cin>>l>>r;
            if(tre.checkdown(1,l,r,1,n)) cout<<1<<'\n';
            else cout<<0<<'\n' ;
        }
        else
        {
            cin>>l>>r;
            //x=tre.find(1,1,n,l);
            int ll=l+1,rr=r,mid,lt=l;
            while(ll<rr)
            {
                mid=(ll+rr)>>1;
                if(tre.checkup(1,l,mid,1,n)) lt=mid,ll=mid+1;
                else rr=mid;
            }
          	if(lt==l) cout<<0<<'\n';
            else if(tre.checkdown(1,lt,r,1,n)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1; //cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}
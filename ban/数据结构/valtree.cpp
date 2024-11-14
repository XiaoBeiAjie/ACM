#include <bits/stdc++.h>
using namespace std;
struct valtree
{
    int tot;
    vector<int> val,cnt,lp,rp,sum;
    valtree(int n)
    {
        val.resize(4*n+5,0);cnt.resize(4*n+5,0);
        lp.resize(4*n+5,0);rp.resize(4*n+5,0);sum.resize(4*n+5,0);
        tot=1;
    }
    void push(int tr)
    {
        cnt[tr]=cnt[lp[tr]]+cnt[rp[tr]];
        sum[tr]=sum[lp[tr]]+sum[rp[tr]];
    }
    void update(int tr,int k,int x,int l=1,int r=2e9)
    {
        if(l>=r) return cnt[tr]+=k,val[tr]=x,sum[tr]+=k*x,void();
        int mid=(l+r)>>1;
        if(x<=mid) update(lp[tr]=lp[tr]?lp[tr]:++tot,k,x,l,mid);
        else update(rp[tr]=rp[tr]?rp[tr]:++tot,k,x,mid+1,r);
        push(tr);
    }
    int kth(int tr,int k,int l=1,int r=2e9)
    {
        if(l>=r) return val[tr];
        int mid=(l+r)>>1;
        if(cnt[lp[tr]=lp[tr]?lp[tr]:++tot]>=k) return kth(lp[tr],k,l,mid);
        else return kth(rp[tr]=rp[tr]?rp[tr]:++tot,k-cnt[lp[tr]],mid+1,r);
    }
    int ksum(int tr,int k,int l=1,int r=2e9)
    {
        if(l>=r) return k*val[tr];
        int mid=(l+r)>>1;
        if(cnt[lp[tr]=lp[tr]?lp[tr]:++tot]>=k) return ksum(lp[tr],k,l,mid);
        else return sum[lp[tr]]+ksum(rp[tr]=rp[tr]?rp[tr]:++tot,k-cnt[lp[tr]],mid+1,r);
    }
};
int main()
{
    valtree tex(100000);
    tex.update(1,100,114);//插入114个100
    tex.update(1,350,200);
    tex.update(1,-50,114);
    cout<<tex.kth(1,50)<<'\n';//第50小数
    cout<<tex.ksum(1,50)<<'\n';//前50小数之和
    cout<<tex.kth(1,51)<<'\n';
    cout<<tex.ksum(1,51)<<'\n';
}
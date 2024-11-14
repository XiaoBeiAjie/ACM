#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
struct node
{
    int l,r,h;
    bool operator<(const node &op)
    {
        if(h==op.h) 
        {
            if(l==op.l) return r<op.r;
            else return l<op.l;
        }
        return h>op.h;
    }
};

int find(node x,vector<node>&a,int l,int r)
{
    int res=r,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(a[mid].r>=x.r) res=mid,r=mid;
        else l=mid+1;
    }
    return res;
}

void solve() {
    int n;cin>>n;
    vector<node> a(n);
    for(int i=0;i<n;++i) 
    {
        cin>>a[i].l>>a[i].r>>a[i].h;
    }
    sort(a.begin(),a.end());
    /*
    for(int i=0;i<n;++i)
    {
        cout<<a[i].h<<' '<<a[i].l<<' '<<a[i].r<<'\n';
    }
    */
    //a.push_back({2000,0,-1});
    int h,x,i=0;cin>>x>>h;
    while(i<n)
    {
        while(i<n&&a[i].h>h) ++i;
        if(i==n) break;
        int j=i;
        while(j<n&&a[j].h==a[i].h) ++j;
        //i=lower_bound(a.begin()+i,a.end(),node(h,x,x))-a.begin();
        //cout<<i<<' '<<j<<'\n';
        i=find(node(-1,x,h),a,i,j);
        //cout<<h<<' '<<x<<' '<<i<<'\n';
        if(i!=j&&a[i].l<x) x=a[i].r;
        //cout<<h<<' '<<x<<' '<<i<<'\n';
        i=j;
        if(i!=n) h=a[i].h;
    }
    cout<<x<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
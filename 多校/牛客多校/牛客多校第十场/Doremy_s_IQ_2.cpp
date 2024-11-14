#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    vector<int> b(n,1);
    vector<ll> cnt(2*n+2,0);
    for(int i=0;i<n;++i) 
    {
        cin>>a[i],++cnt[a[i]+n+1];
        if(i&&a[i]==a[i-1]) b[i]=b[i-1]+1;
    }
    for(int i=1;i<=2*n+1;++i) cnt[i]+=cnt[i-1];
    int l=1,r=n+1,ans=0,mid;
    auto check=[&]()->bool
    {
        for(int j=mid-1,i=0;j<n;++j,++i)
        {
            int ll=a[i],rr=a[j];
            if(ll>0) ll=0;
            else if(rr<0) rr=0;
            if(cnt[2*n+1]-cnt[a[j]+n]-b[j]>=rr&&cnt[a[i]+n]+b[i]-1>=rr-ll) return true;
            if(cnt[a[i]+n]+b[i]-1>=-ll&&cnt[2*n+1]-cnt[a[j]+n]-b[j]>=rr-ll) return true;
        }
        return false;
    };
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check()) ans=mid,l=mid+1;
        else r=mid;
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
/*
4
19
-2 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 2 2 2 2 2 2
19
-2 -2 -2 -2 -2 -2 -1 -1 -1 -1 1 1 1 1 1 1 1 1 2
8
-8 -1 8 8 8 8 8 8 
8
-8 -8 -8 -8 -8 -8 1 8
*/
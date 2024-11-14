#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    auto solve=[]()
    {
        int n;cin>>n;
        vector<array<int,2>> f(n);
        int l=1,r=1e9+1,mid,ans;
        for(int i=0;i<n;++i) cin>>f[i][0]>>f[i][1];
        auto check=[&](int mid)
        {
            int cnt=0,mn=0,cur=0,mx=0;
            for(int i=0;i<n;++i)
            {
                if(f[i][0]>=mid) ++cnt;
                if(f[i][0]>=mid&&f[i][1]>=mid) cur+=0;
                else if(f[i][0]<mid&&f[i][1]<mid) cur+=0;
                else if(f[i][0]>=mid&&f[i][1]<mid) --cur;
                else ++cur;
                mx=max(mx,cur-mn);
                mn=min(mn,cur);
            }
            return cnt+mx>=(n+1)/2;
        };
        while(l<r)
        {
            mid=(l+r)>>1;
            if(check(mid)) l=mid+1,ans=mid;
            else r=mid;
        }
        cout<<ans<<'\n';
    };
    solve();
}
#include <bits/stdc++.h>

using namespace std;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    auto solve=[&]()->void
    {
        int la,ra,lb,rb;cin>>la>>ra>>lb>>rb;
        int m=la+lb,n=rb+ra;
        if(n-m>=9) return cout<<9<<'\n',void();
        int ans=0;
        for(int i=m;i<=n;++i)
        {
            int j=i;
            while(j) ans=max(ans,j%10),j/=10;
        }
        cout<<ans<<'\n';
    };
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
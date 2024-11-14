#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int k,m,h;cin>>m>>k>>h;
    if(k==m) cout<<min(m,h)<<'\n';
    else if(h<m) cout<<h<<'\n';
    else
    {
        int l=m,r=h+1,mid,ans;
        int tot=0;
        auto check=[&]()->bool
        {
            if((mid-m)/(m-k)<m)
            {
                ll res=1ll*mid+1ll*(mid-m)/(m-k)*k;
                return res>=h;
            }
            
            ll res=mid,sum=mid;
            while(res>=m)
            {
                ++tot;
                ll t=res/m*k;
                sum+=t;res%=m;res+=t;
                if(sum>=h) return true;
            }
            return false;
            
        };
        while(l<r)
        {
            mid=(l+r)>>1;
            if(check()) r=mid,ans=mid;
            else l=mid+1;
        }
        //cout<<tot<<'\n';
        cout<<ans<<'\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
/*
1000999
500500000
800200000
970030000
999800200

1000999
500500000
800200000
970030000
999800200
*/
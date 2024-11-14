#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int ans=n+1,cnt=0;
    for(int i=1;i<n;++i)
    {
        if(a[i]%a[0]) ++cnt;
    }
    if(!cnt) ans=n-1;
    if(cnt==1) ans=n;
    if(ans>n)
    {
        int gd=-1;
        for(int i=1;i<n;++i)
        {
            if(a[i]%a[0])
            {
                if(gd==-1) gd=a[i];
                else gd=__gcd(gd,a[i]);
            }
        }
        if(gd>a[0]) ans=n;
    }
    for(int i=0;i<n&&ans>n;++i)
    {
        for(int j=i+1;j<n&&ans>n;++j)
        {
            int t=a[j]%a[i];
            for(int k=0;k<n&&t;++k)
            {
                if(k==j) continue;
                if(a[k]%t) t=0;
            }
            if(t) ans=n;
        }
    }
    cout<<ans<<'\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
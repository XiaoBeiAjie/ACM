#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,k;cin>>n>>k;
    if(k==n-2) return cout<<"-1"<<'\n',void();
    int t=n;
    if(k>=1)
    {
        --k;
        for(int i=n-(k+1);i<=n;++i) cout<<i<<' ',--t;
    }
    if(t<=3) for(int i=t;i;--i) cout<<i<<" \n"[i==1];
    else
    {
        //cout<<1<<' ';--t;
        int tt=(t+2)/3;
        int x=t-tt+1,l=x/2+1,r=x-l;
        while(t)
        {
            if(t) cout<<(x++)<<' ',--t;
            if(t) cout<<(l++)<<' ',--t;
            if(t) cout<<(r--)<<' ',--t;
        }
        cout<<'\n';
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
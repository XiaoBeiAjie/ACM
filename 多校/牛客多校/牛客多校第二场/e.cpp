#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll x;cin>>x;
    for(int i=0;i<=61;++i)
    {
        if((x>>i)&1)
        {
            if((1ll<<i)==x) cout<<-1<<'\n';
            else 
            {
                x-=1ll<<i;
                cout<<x<<'\n';
            }
        }
        return;
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
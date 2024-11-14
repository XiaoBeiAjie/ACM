#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,m,a,b;cin>>n>>m>>a>>b;
    ll t=1ll*n*m;
    if(t&1) cout<<"No\n";
    else if(a==1&&b==1) cout<<"Yes\n";
    else if(a==0&&b==0)
    {
        if(t==2) cout<<"Yes\n";
        else cout<<"No\n";
    }
    else if(a==0) cout<<"Yes\n";
    else if(n==1||m==1) cout<<"Yes\n";
    else cout<<"No\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
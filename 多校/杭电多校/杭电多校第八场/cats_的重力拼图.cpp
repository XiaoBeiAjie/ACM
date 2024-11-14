#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n,m,a,b;cin>>n>>m>>a>>b;
    int ans=0;
    if(n==1||m==1) ans=n*m;
    else if((a==1||a==n)&&(b==1||b==m)) ans=n*2+m*2-4;
    else if(a==1||a==n) ans=n*2+m*2-4+n-2;
    else if(b==1||b==m) ans=n*2+m*2-4+m-2;
    else ans=n*2+m*2-4+max(n,m)-2;
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
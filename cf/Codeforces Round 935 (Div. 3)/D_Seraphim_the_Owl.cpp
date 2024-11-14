#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i];
    ll sum = 0, ans = 1e18;
    for (int i = n; i > m; i -- ) 
        sum += min(a[i], b[i]);
    for (int i = m; i; i -- ) 
        ans = min(ans, sum + a[i]), sum += b[i];
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
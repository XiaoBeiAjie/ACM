#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
void solve() {
    int n; cin >> n;
    vector g(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i ++ ) {
        int x, y; cin >> x >> y;
        g[x][y] = 1;
    }
    i64 ans = 0;
    for (int i = 0; i <= n; i ++ ) 
        if (g[i][1] && g[i][0]) 
            ans += n - 2;
    for (int i = 1; i < n; i ++ ) {
        if (g[i][1] && g[i - 1][0] && g[i + 1][0]) ans ++;
        if (g[i][0] && g[i - 1][1] && g[i + 1][1]) ans ++;
    }
    cout << ans << "\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
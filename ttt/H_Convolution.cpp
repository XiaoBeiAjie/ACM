#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector g(n + 1, vector<i64>(m + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cin >> g[i][j];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
    i64 ans = 0;
    for (int i = n - k + 1; i <= n; i ++ ) 
        for (int j = m - l + 1; j <= m; j ++ ) 
            ans += llabs(g[i][j] - g[i - (n - k + 1)][j] - g[i][j - (m - l + 1)] + g[i - (n - k + 1)][j - (m - l + 1)]); 
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T =  1;
    while (T -- ) solve();
    return 0;
}
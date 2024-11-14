#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector e(n + 1, vector<int>());
    for (int i = 1; i <= m; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    if ((!(n & 1)) && (!(m & 1))) 
        return cout << 0 << "\n", void();
    int ans = 0;
    if (n & 1) {
        for (int i = 1; i <= n; i ++ ) 
            if (!((m - e[i].size()) & 1)) ans ++;
    }
    else ans = m;
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
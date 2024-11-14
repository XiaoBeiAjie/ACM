#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> f(m + 1);
    for (int i = 1; i <= n; i ++ ) {
        vector<int> g(m + 1);
        for (int j = w[i]; j <= m; j ++ ) 
            g[j] = min(f[j], f[j - w[i]] + 1);
        f = move(g);
        swap(f, g);
    }
    if (f[m] == inf) return cout << "-1\n", void();
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int len = 510;
    vector<int> primes;
    vector<bool> st(len);
    for (int i = 2; i < len; i ++ ) {
        if (!st[i]) primes.push_back(i);
        for (int j = 0; primes[j] < len / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) 
                break;
        }
    }
    int n; cin >> n;
    vector<int> w(n + 1);
    vector f(n + 1, map<int, int>());
    vector p(n + 1, vector<int>());
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        for (int j = 0; j < primes.size() && primes[j] <= w[i]; j ++ ) {
            if (w[i] % primes[j] == 0) {
                while (w[i] % primes[j] == 0) w[i] /= primes[j];
                f[i][primes[j]] = 1;
                p[i].push_back(primes[j]);
                ans = 1;
            }
        }
        // for (int j = 2; j * j <= w[i]; j ++ ) 
        //     if (w[i] % j == 0) {
        //         while (w[i] % j == 0) 
        //             w[i] /= j;
        //         f[i][j] = 1;
        //         p[i].push_back(j);
        //         ans = 1;
        //     }
        if (w[i] != 1) {
            f[i][w[i]] = 1;
            p[i].push_back(w[i]);
            ans = 1;
        }
    }
    vector e(n + 1, vector<int>());
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    function<void(int, int)> dfs = [&] (int u, int fa) {
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            for (auto t : p[u]) 
                for (auto tt : p[v]) 
                    if (t == tt) {
                        ans = max(ans, f[u][t] + f[v][t]);
                        f[u][t] = max(f[u][t], f[v][t] + 1);
                    }
        }
    };
    dfs(1, 0);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
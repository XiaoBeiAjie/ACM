#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector e(n + 1, vector<int> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    int q; cin >> q;
    vector que(n + 1, vector<array<int, 2>> ());
    while (q -- ) {
        int u, d, x; 
        cin >> u >> d >> x;
        que[u].push_back({d, x});
    }
    vector<i64> val(n + 1), pre(n + 1);
    vector<int> dep(n + 1);
    i64 sum = 0;
    function<void(int, int)> dfs = [&] (int u, int fa) {
        dep[u] = dep[fa] + 1;
        for (auto [d, x] : que[u]) {
            pre[dep[u]] += x;
            if (dep[u] + d + 1 <= n) 
                pre[dep[u] + d + 1] -= x;
        }
        sum += pre[dep[u]];
        val[u] = sum;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
        }
        sum -= pre[dep[u]];
        for (auto [d, x] : que[u]) {
            pre[dep[u]] -= x;
            if (dep[u] + d + 1 <= n) 
                pre[dep[u] + d + 1] += x;
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i ++ ) 
        cout << val[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
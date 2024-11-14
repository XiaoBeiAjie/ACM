#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, w; cin >> n >> w;
    vector<int> p(n + 1);
    vector e(n + 1, vector<int>());
    for (int i = 2; i <= n; i ++ ) {
        cin >> p[i];
        e[i].push_back(p[i]);
        e[p[i]].push_back(i);
    }
    int dfn = 0;
    vector<int> cnt(n + 1);
    vector f(n + 1, array<int, 2>());
    function<void(int, int)> dfs = [&] (int u, int fa) {
        dfn ++;
        for (auto v : e[u]) {
            if (v == fa) continue;
            f[v][0] = dfn; cnt[dfn] ++;
            dfs(v, u);
            f[v][1] = dfn; cnt[dfn] ++;
        }
    };
    dfs(1, 0);
    i64 tot = n, sum = 0;
    for (int i = 2; i <= n; i ++ ) {
        i64 x, y; cin >> x >> y;
        if (!(-- cnt[f[x][0]])) tot --;
        if (!(-- cnt[f[x][1]])) tot --;
        sum += y;
        cout << tot * (w - sum) + sum + sum << " \n"[i == n];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
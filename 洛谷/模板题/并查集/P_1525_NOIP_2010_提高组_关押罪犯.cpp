#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve1() {
    int n, m; cin >> n >> m;
    vector e(n + 1, vector<array<int, 2>>());
    while (m -- ) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    function<bool(int)> check = [&] (int mid) {
        queue<int> q;
        vector<int> f(n + 1, -1);
        for (int i = 1; i <= n; i ++ ) {
            if (~f[i]) continue;
            q.push(i);
            f[i] = 0;
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                for (auto [v, w] : e[u]) {
                    if (w < mid) continue;
                    if (!~f[v]) {
                        f[v] = f[u] ^ 1;
                        q.push(v); 
                    } 
                    else if (f[v] == f[u]) return false;
                }
            }
        }
        return true;
    };
    int l = 0, r = 1000000010;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << max(0, l - 1) << "\n";
}

void solve() {
    int n, m; cin >> n >> m;
    vector e(m + 1, array<int, 3>());
    vector<int> p(n << 1 | 1);
    for (int i = 1; i <= n << 1; i ++ ) 
        p[i] = i;
    function<int(int)> find = [&] (int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    };
    for (int i = 1; i <= m; i ++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {w, u, v};
    }
    sort(e.begin() + 1, e.end());
    reverse(e.begin() + 1, e.end());
    for (int i = 1; i <= m; i ++ ) {
        auto [w, u, v] = e[i];
        int fu = find(u), fv = find(v);
        if (fu == fv) 
            return cout << w << "\n", void();
        p[fu] = find(v + n);
        p[fv] = find(u + n); 
    }
    cout << "0\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
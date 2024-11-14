#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k, q; cin >> n >> m >> k >> q;
    int hi = 0;
    vector pos(n + 1, vector<int>());
    for (int i = 1; i <= k; i ++ ) {
        int x, y; cin >> x >> y;
        pos[x].push_back(y);
        hi = max(x, hi);
    }
    set<int> c;
    for (int i = 1; i <= q; i ++ ) {
        int x; cin >> x;
        c.insert(x);
    }
    unordered_map<int, i64> f;
    f[1] = 0;
    constexpr i64 inf = LLONG_MAX;
    if (pos[1].empty()) 
        f.erase(1); f[*c.begin()] = *c.begin() - 1;
    for (int i = 1; i < hi; i ++ ) {
        if (pos[i].empty()) continue;
        sort(pos[i].begin(), pos[i].end());
        unordered_map<int, i64> g;
        int l = *pos[i].begin(), r = *prev(pos[i].end());
        int l_1 = 0, l_2 = 0, r_1 = 0, r_2 = 0;
        auto u = c.lower_bound(l);
        if (u != c.end()) l_2 = *u, g[l_2] = inf;
        if (u != c.begin()) l_1 = *prev(u), g[l_1] = inf;
        auto v = c.lower_bound(r);
        if (v != c.end()) r_2 = *v, g[r_2] = inf;
        if (v != c.begin()) r_1 = *prev(v), g[r_1] = inf;
        for (auto [idx, w] : f) {
            if (l_2) g[l_2] = min(g[l_2], w + min(abs(idx - l) + (r - l) + abs(r - l_2),
             abs(idx - r) + (r - l) + abs(l - l_2)));
            if (l_1) g[l_1] = min(g[l_1], w + min(abs(idx - l) + (r - l) + abs(r - l_1),
             abs(idx - r) + (r - l) + abs(l - l_1)));
            if (r_2) g[r_2] = min(g[r_2], w + min(abs(idx - r) + (r - l) + abs(l - r_2),
             abs(idx - l) + (r - l) + abs(r - r_2)));
            if (r_1) g[r_1] = min(g[r_1], w + min(abs(idx - r) + (r - l) + abs(l - r_1),
             abs(idx - l) + (r - l) + abs(r - r_1)));
        }
        f = move(g);
    }
    {
        sort(pos[hi].begin(), pos[hi].end());
        unordered_map<int, i64> g;
        int l = *pos[hi].begin(), r = *prev(pos[hi].end());
        g[l] = inf, g[r] = inf;
        for (auto [idx, w] : f) 
            g[l] = min(g[l], w + abs(idx - r) + (r - l)),
            g[r] = min(g[r], w + abs(idx - l) + (r - l));
        f = move(g);
    }
    i64 ans = inf;
    for (auto [idx , w] : f) 
        ans = min(ans, w);
    cout << ans + hi - 1 << "\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
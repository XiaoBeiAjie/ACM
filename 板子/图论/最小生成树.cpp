#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& rh) const {
        return w < rh.w;
    };
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e(m);
    for (int i = 0; i < m; i ++ ) 
        cin >> e[i].u >> e[i].v >> e[i].w;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        p[i] = i;
    function<int(int)> find = [&] (int x) {
        return x == p[x] ? x : find(p[x]);
    };
    int ans = 0, cnt = 0;
    function<void()> kruskal = [&] () {
        sort(e.begin(), e.end());
        for (auto [u, v, w] : e) {
            u = find(u), v = find(v);
            if (u == v) 
                continue;
            ans += w, cnt ++;
            p[v] = u;
            if (cnt == n - 1) break;
        }
    };
    kruskal();
    if (cnt == n - 1) cout << ans << "\n";
    else cout << "orz\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector e(n + 1, vector<int> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<ll> dist(n + 1), f(n + 1), siz(n + 1);
    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        f[u] = dist[u], siz[u] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dist[v] = dist[u] + 1;
            dfs1(v, u);
            f[u] += f[v], siz[u] += siz[v];
        }
    };
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        if (u != 1) {
            f[u] = f[fa] - f[u] + dist[fa] * siz[u] + (n - siz[u]);
            for (auto v : e[u]) {
                if (v == fa) continue;
                f[u] += f[v] - dist[u] * siz[v];
            }
        }
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs2(v, u);
        }

    };
    function<void(int, int)> dfs3 = [&] (int u, int fa) {
        for (auto v : e[u]) {
            if (v == fa) continue;
            f[v] = f[u] + siz[1] - 2 * siz[v];
            dfs3(v, u);
        }
    };
    dfs1(1, 0);
    //dfs2(1, 0);
    dfs3(1, 0);
    cout << max_element(f.begin(), f.end()) - f.begin() << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
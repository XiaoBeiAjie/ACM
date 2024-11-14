#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector e(n + 1, vector<array<int, 2>> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector<int> f(n + 1);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        vector<int> g(m + 1);
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            for (int j = m; j; j -- ) 
                for (int i = 0; i < j; i ++ ) 
                    g[j] = max(g[j], g[j - i - 1] + f[i] + w);
        }
        f = move(g);
    };
    dfs(1, 0);
    cout << f[m] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
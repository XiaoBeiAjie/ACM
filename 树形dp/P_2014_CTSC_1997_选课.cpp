#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector e(n + 1, vector<array<int, 2>> ());
    for (int i = 1; i <= n; i ++ ) {
        int u, w;
        cin >> u >> w;
        e[u].push_back({i, w});
    }
    vector<int> f(m + 1);
    function<void(int)> dfs = [&] (int u) {
        vector<int> g(m + 1);
        for (auto [v, w] : e[u]) {
            dfs(v);
            for (int j = m; j; j -- ) 
                for (int i = 0; i < j; i ++ ) 
                    g[j] = max(g[j], g[j - i - 1] + f[i] + w);
        }
        f = move(g);
    };
    dfs(0);
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
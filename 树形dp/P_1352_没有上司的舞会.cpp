#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector e(n + 1, vector<int> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector f(n + 1, array<int, 2> ());
    function<void(int, int)> dfs = [&] (int u, int fa) {
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            f[u][0] += max({0, f[v][1], f[v][0]});
            f[u][1] += max({0, f[v][0]});
        }
        f[u][1] += w[u];
    };
    dfs(1, 0);
    cout << max(f[1][1], f[1][0]) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
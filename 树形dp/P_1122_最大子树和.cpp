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
    vector<int> f(n + 1);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        f[u] = w[u];
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            if (f[v] > 0) f[u] += f[v];
        }
    };
    dfs(1, 0);
    int ans = INT32_MIN;
    for (int u = 1; u <= n; u ++ ) 
        ans = max(ans, f[u]);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
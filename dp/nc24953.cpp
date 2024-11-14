#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector adj(n + 1, vector<int> ());
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<int, 3>> f(n + 1);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        f[u][0] = 1;
        bool flag = true;
        int res = 0x3f3f3f3f;
        for (auto v : adj[u]) {
            if (v == fa) continue;
            dfs(v, u);
            f[u][0] += min({f[v][0], f[v][1], f[v][2]});
            f[u][2] += min(f[v][0], f[v][1]);
            if (f[v][0] <= f[v][1]) {
                flag = false;
                f[u][1] += f[v][0];
            }
            else {
                f[u][1] += f[v][1];
                res = min(f[v][0] - f[v][1], res);
            }
        }
        if (flag) f[u][1] += res;
    };
    dfs(1, 0);
    cout << min(f[1][0], f[1][1]) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector e(n, vector<int> ());
    for (int i = 1; i <= n; i ++ ) {
        int u, m;
        cin >> u >> m;
        while (m -- ) {
            int v; cin >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    vector f(n, array<int, 2> ());
    function<void(int, int)> dfs = [&] (int u, int fa) {
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            f[u][1] += min(f[v][0], f[v][1]);
            f[u][0] += f[v][1]; 
        }
        f[u][1] ++;
    };
    dfs(0, -1);
    cout << min(f[0][0], f[0][1]) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
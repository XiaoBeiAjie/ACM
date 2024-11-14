#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef long long LL;

vector<LL> w(N + 1);
vector<vector<int>> g(N + 1);

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ )
        g[i].clear();
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m = 21;
    vector f(n + 1, vector<LL> (m + 1, LLONG_MAX));
    function<void(int, int)> dfs = [&] (int u, int fa) {
        for (int i = 1; i <= m; i ++ ) 
            f[u][i] = w[u] * i;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            for (int i = 1; i <= m; i ++ ) {
                LL res = LLONG_MAX;
                for (int j = 1; j <= m; j ++ ) 
                    if (i != j) 
                        res = min(res, f[v][j]);  
                f[u][i] += res;   
            }
        }
    };
    dfs(1, 0);
    cout << *min_element(f[1].begin(), f[1].end()) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
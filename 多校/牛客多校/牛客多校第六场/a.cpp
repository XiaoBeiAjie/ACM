#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<vector<array<int, 2>>> e(n + 1);
    for (int i = 1; i < n; i ++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    long double res = 1.0;
    vector<long double> f(n + 1);
    function<void(int, int, bool, int, int)> dfs = [&] (int u, int fa, bool t, int cnt1, int cnt2) { 
        if (e[u].size() == 1 && u != 1) {
            f[u] = (res * cnt2) / (cnt2 + cnt1);
            return ;
        }
        if (t == 1) {
            long double tmp = res;
            for (auto [v, w] : e[u]) {
                if (v == fa) continue;
                dfs(v, u, t ^ 1, cnt1 + (w == 1), cnt2 + (w == 0));
                tmp = min(tmp, f[v]);
                if (u == 1) f[u] = 0;
                else f[u] = (res * cnt2) / (cnt2 + cnt1);
                f[u] = max(f[u], tmp);
            }
        }
        else {
            f[u] = (res * cnt2) / (cnt2 + cnt1);
            for (auto [v, w] : e[u]) {
                if (v == fa) continue;
                dfs(v, u, t ^ 1, cnt1 + (w == 1), cnt2 + (w == 0));
                f[u] = max(f[u], f[v]);
            }
        }
    };
    dfs(1, 0, 1, 0, 0);
    cout << fixed<<setprecision(11)<< res - f[1] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
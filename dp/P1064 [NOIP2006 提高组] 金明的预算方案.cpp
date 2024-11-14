#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1), w(n + 1), p(n + 1);
    vector<array<int, 2>> son(n + 1); 
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i] >> v[i] >> p[i];
        if (p[i]) 
            if (son[p[i]][0]) son[p[i]][1] = i;
            else son[p[i]][0] = i;
    }
    vector<int> f(m + 1, -0x3f3f3f3f);
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (p[i]) continue;
        vector<int> g(m + 1);
        for (int j = 1; j <= m; j ++ ) {
            g[j] = f[j];
            if (j >= w[i]) 
                g[j] = max(f[j - w[i]] + v[i] * w[i], g[j]);
            if (j >= w[i] + w[son[i][0]]) 
                g[j] = max(f[j - w[i] - w[son[i][0]]] + w[i] * v[i] + w[son[i][0]] * v[son[i][0]], g[j]);
            if (j >= w[i] + w[son[i][1]])
                g[j] = max(f[j - w[i] - w[son[i][1]]] + w[i] * v[i] + w[son[i][1]] * v[son[i][1]], g[j]); 
            if (j >= w[i] + w[son[i][0]] + w[son[i][1]])
                g[j] = max(f[j - w[i] - w[son[i][0]] - w[son[i][1]]] + w[son[i][0]] * v[son[i][0]] + w[i] * v[i] + w[son[i][1]] * v[son[i][1]], g[j]); 
        }
        f = g;
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++ ) 
        ans = max(ans, f[i]);
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
#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
typedef long long ll;

struct OL {
    int id, l, h;
    bool operator < (const OL &rh) const {
        return id < rh.id;
    }
};

void solve() {
    int n, m , k, idx = 1;
    cin >> n >> m >> k;
    vector<int> x(n + 1), y(n + 1);
    vector<OL> ol(k + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> x[i] >> y[i];
    for (int i = 1; i <= k; i ++ ) 
        cin >> ol[i].id >> ol[i].l >> ol[i].h;
    sort(ol.begin() + 1, ol.end());
    vector<int> f(2 * m + 1, 0);
    for (int i = 1; i <= n; i ++ ) {
        vector<int> g(2 * m + 1, INF);
        for (int j = x[i] + 1; j <= m + x[i]; j ++ ) 
            g[j] = min(f[j - x[i]] + 1, g[j - x[i]] + 1);
        for (int j = m - y[i]; j; j -- ) 
            g[j] = min(f[j + y[i]], g[j]);
        for (int j = m + 1; j <= m + x[i]; j ++ ) 
            g[m] = min(g[j], g[m]);
        if (idx <= k && i == ol[idx].id) {
            for (int j = 1; j <= ol[idx].l; j ++ ) 
                g[j] = INF;
            for (int j = m; j >= ol[idx].h; j -- ) 
                g[j] = INF;
            int ans = INF;
            for (int j = ol[idx].l + 1; j < ol[idx].h; j ++ )
                ans = min(ans, g[j]);
            if (ans == INF) {
                cout << "0\n" << idx - 1 << "\n";
                return ;
            }
            idx ++;
        }
        f = g;
    }
    int ans = INF;
    for (int i = 1; i <= m; i ++ ) 
        ans = min(ans, f[i]);
    cout << "1\n" << ans << "\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
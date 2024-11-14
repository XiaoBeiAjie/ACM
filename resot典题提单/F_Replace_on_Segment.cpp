#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    constexpr int inf = 0x3f3f3f3f;
    vector f(n + 1, vector (n + 1, vector<int> (x + 1, inf)));
    vector g(n + 1, vector (n + 1, vector<int> (x + 1, inf)));
    for (int len = 1; len <= n; len ++ ) {
        for (int l = 1; l + len - 1 <= n; l ++ ) {
            int r = l + len - 1;
            if (len == 1) {
                for (int k = 1; k <= x; k ++ ) 
                    if (w[l] == k) 
                        f[l][r][k] = 0, g[l][r][k] = 1;
                    else 
                        f[l][r][k] = 1, g[l][r][k] = 0;
                continue;
            }
            int minn = inf;
            for (int k = 1; k <= x; k ++ ) {
                for (int mid = l; mid < r; mid ++ ) 
                    g[l][r][k] = min(g[l][r][k], g[l][mid][k] + g[mid + 1][r][k]);
                minn = min(minn, g[l][r][k]);
            }
            for (int k = 1; k <= x; k ++ ) 
                g[l][r][k] = min(g[l][r][k], minn + 1);
            for (int k = 1; k <= x; k ++ ) {
                for (int mid = l; mid < r; mid ++ ) 
                    f[l][r][k] = min({f[l][r][k], f[l][mid][k] + f[mid + 1][r][k], g[l][r][k] + 1});
            }
        }
    }
    cout << *min_element(f[1][n].begin(), f[1][n].end()) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
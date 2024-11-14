#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int mod = 1000000007;

// void solve() {
//     int n, m; cin >> n >> m;
//     int cnt = 0;
//     vector<int> w(n + 1), c;
//     c.push_back(0);
//     for (int i = 1; i <= n; i ++ ) {
//         cin >> w[i];
//         if (w[i] == 1) 
//             cnt ++, c.push_back(i);
//     }
//     vector f(n + 1, vector (n + 1, vector<i64> (m + 1)));
//     f[0][0][0] = 1;
//     for (int i = 1; i <= n; i ++ ) 
//         for (int j = 0; j <= cnt; j ++ ) 
//             for (int k = 0; k <= m; k ++ ) {
//                 f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
//                 if (j && k >= abs(i - c[j])) 
//                     f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k - abs(i - c[j])]) % mod;
//             }
//     i64 ans = 0;
//     for (int k = m; k >= 0; k -= 2) 
//         ans = (ans + f[n][cnt][k]) % mod;
//     cout << ans << "\n";
// }

void solve() {
    int n, m; cin >> n >> m;
    int cnt = 0;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ )
        cin >> w[i];
    vector f(81, vector<i64> (m + 1));
    constexpr int base = 40;
    f[base][0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        vector g(81, vector<i64> (m + 1));
        for (int j = -base; j <= base; j ++ ) 
            for (int bit = 0; bit <= 1; bit ++ ) {
                int nj = j + bit - w[i];
                if (abs(nj) > base) continue;
                for (int k = 0; k + abs(nj) <= m; k ++ ) 
                    g[nj + base][k + abs(nj)] = (g[nj + base][k + abs(nj)] + f[j + base][k]) % mod;
            }
        f = move(g);
    }
    i64 ans = 0;
    for (int k = m; k >= 0; k -= 2)
        ans = (ans + f[base][k]) % mod;
    cout << ans << "\n"; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
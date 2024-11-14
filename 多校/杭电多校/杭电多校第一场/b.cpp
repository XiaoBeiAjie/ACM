#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<LL, 4>> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 0; j < 4; j ++ ) 
            cin >> a[i][j];
    vector<LL> f(k + 1, 4e18);
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        vector<vector<LL>> g(4);
        for (int t = 0; t < 4; t ++ ) {
            g[t] = f; 
            for (int j = k; j - t - 1 >= 0; j -- ) 
                g[t][j] = min(g[t][j], f[j - t - 1] + a[i][t]);
            
        }
        for (int j = 0; j <= k; j ++ ) 
            f[j] = min({f[j], g[0][j], g[1][j], g[2][j], g[3][j]});
    }
    cout << f[k] << endl;  
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector f(n + 1, vector(n + 1, vector<int> (n + 1)));
    for (int i = 0; i <= n; i ++ ) 
        for (int j = 0; j <= n; j ++ ) 
            for (int k = 0; k <= n; k ++ ) {
                if (!i || !j || !k) 
                    f[i][j][k] = 1;
                else {
                    int res = 0;
                    if (a[i] == a[j] && a[j] == a[k]) 
                        res = f[i - 1][j - 1][k - 1];
                    f[i][j][k] = ((((((res + f[i - 1][j][k]) % mod + f[i][j - 1][k]) % mod + f[i][j][k - 1]) % mod
                        - ((f[i - 1][j - 1][k] + f[i - 1][j][k - 1]) % mod + f[i][j - 1][k - 1]) % mod) % mod + mod) % mod
                         + f[i - 1][j - 1][k - 1]) % mod;
                }
            }
    cout << (f[n][n][n] - 1 + mod )% mod << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
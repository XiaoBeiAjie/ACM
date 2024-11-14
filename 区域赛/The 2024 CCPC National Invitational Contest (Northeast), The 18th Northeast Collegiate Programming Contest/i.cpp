#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long LL;

int T;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> f(n + 10);
    vector<LL> g(k + 10), c(k + 10);
    c[0] = 1;
    for (int i = 1; i <= k; i ++ ) 
        c[i] = i * c[i - 1] % mod;
    for (int i = 1; i <= k; i ++ ) {
        g[i] = c[i];
        for (int j = 1; j <= i - 1; j ++ ) 
            g[i] = (g[i] - c[j] * g[i - j] % mod + mod) % mod;
    }
    f[k] = c[k];
    for (int i = k + 1; i <= n; i ++ ) 
        for (int j = 1; j <= k; j ++ ) 
            f[i] = (f[i] + f[i - j] * g[j] % mod) % mod;
    cout << f[n] << endl;   
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
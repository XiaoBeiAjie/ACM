#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
typedef long long LL;

int n, w[N];
int f[2][N];
LL fnc[N], inv[N];

int C(int a, int b) {
    return 1ll * fnc[a] * inv[b] % mod * 1ll * inv[a - b] % mod;
}

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fnc[0] = 1, inv[0] = 1;
    for (int i = 1; i <= 501; i ++ ) fnc[i] = 1ll * fnc[i - 1] * i % mod;
    inv[501] = qmi(fnc[501], mod - 2);
    for (int i = 500; i; i -- ) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    int sum = 0;
    f[0][1] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= sum + 1; j ++ ) f[i & 1][j] = 0;
        for (int j = 0; j <= sum + 1; j ++ ) {
            for (int k = 1; k < j; k ++ ) 
                for (int x = 0; x < w[i]; x ++ ) 
                    f[i & 1][x + k + 1] = (f[i & 1][x + k + 1] + 1ll * f[i & 1 ^ 1][j] * C(j - 1 - k + w[i] - x - 1, w[i] - x - 1) % mod) % mod;
            f[i & 1][w[i] + j] = (f[i & 1][w[i] + j] + f[i & 1 ^ 1][j]) % mod;    
        }
        sum += w[i];
    }
    int ans = 0;
    for (int i = 2; i <= sum + 1; i ++ ) ans = (ans + f[n & 1][i]) % mod; 
    cout << ans << endl;
}

int main (void) {
    int T = 1;
    init();
    while (T -- ) solve();
    return 0;
}

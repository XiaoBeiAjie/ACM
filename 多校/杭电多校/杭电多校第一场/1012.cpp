#include <bits/stdc++.h>
using namespace std;
const int N = 2010, mod = 998244353;
typedef long long ll;

int fac[N], inv[N];

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int binom(int n, int m) {
    if (n < m) return 0;
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod; 
}

void solve() {
    int n; cin >> n;
    vector<int> x1(n + 1), x2(n + 1), y1(n + 1), y2(n + 1);
    vector<int> vx, vy;
    vx.push_back(0), vy.push_back(0);
    for (int i = 1; i <= n; i ++ ) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        vx.push_back(x1[i]), vx.push_back(x2[i]);
        vy.push_back(y1[i]), vy.push_back(y2[i]);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    int nx = vx.size(), ny = vy.size();
    vector f(nx, vector<int> (ny));
    for (int i = 1; i <= n; i ++ ) {
        x1[i] = lower_bound(vx.begin(), vx.end(), x1[i]) - vx.begin();
        x2[i] = lower_bound(vx.begin(), vx.end(), x2[i]) - vx.begin();
        y1[i] = lower_bound(vy.begin(), vy.end(), y1[i]) - vy.begin();
        y2[i] = lower_bound(vy.begin(), vy.end(), y2[i]) - vy.begin();
        f[x1[i]][y1[i]] ++;
        // 离散的点， 在末尾点直接更改
        f[x1[i]][y2[i]] --;
        f[x2[i]][y1[i]] --;
        f[x2[i]][y2[i]] ++;
    }
    vector<int> g(n + 1);
    for (int i = 1; i < nx; i ++ )
        for (int j = 1; j < ny; j ++ ) {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            if (i != nx - 1 && j != ny - 1) 
                g[f[i][j]] = (g[f[i][j]] + 1ll * (vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j])) % mod;
        }
    for (int k = 1; k <= n; k ++ ) {
        int ans = 0;
        // k个里面包含i的有j个 sigama C(i, j) * C(n - i, k - j) <==> C(n, k) - C(n - i, k) 等价于全部减去k都不在i里
        for (int i = 0; i <= n; i ++ ) 
            ans = (ans + 1ll * ((binom(n, k) - binom(n - i, k)) % mod + mod) % mod * g[i] % mod) % mod;
        cout << 1ll * ans * qmi(binom(n, k), mod - 2) % mod << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i < N; i ++ ) 
        fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[N - 1] = qmi(fac[N - 1], mod - 2);
    for (int i = N - 1; i; i -- ) 
        inv[i - 1] = 1ll * inv[i] * i % mod;
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
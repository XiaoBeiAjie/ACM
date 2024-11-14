#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    constexpr int mod = 998244353;
    function<int(int, int)> qmi = [&] (int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % mod;
            a = 1ll * a * a % mod;
            b >>= 1;
        }
        return res;
    };
    array<int, 2> cnt;
    cnt.fill(0);
    for (int i = 1; i <= n; i ++ )
        cnt[w[i]] ++;
    int st = 0;
    for (int i = n; i >= n - cnt[1] + 1; i -- ) 
        if (w[i] == 1) st ++;
    vector<int> f(cnt[1] + 1);
    //int n_ = qmi(n, mod - 2), n_1 = qmi(n - 1, mod - 2);
    for (int i = st; i < cnt[1]; i ++ ) 
        f[i + 1] = (f[i] + 1ll * n * (n - 1) % mod * qmi(2, mod - 2) % mod * qmi(cnt[1] - i, mod - 2) % mod * qmi(cnt[1] - i, mod - 2) % mod) % mod;
    cout << f[cnt[1]] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
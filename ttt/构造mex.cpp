#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int s, n, k; cin >> s >> n >> k;
    if (!k) {
        if (s < n) return cout << "NO\n", void();
        cout << "YES\n";
        cout << s - n + 1 << " ";
        for (int i = 2; i <= n; i ++ ) 
            cout << 1 << " ";
        cout << "\n";
        return ;
    }
    if (k > n) return cout << "NO\n", void();
    if (1ll * k * (k - 1) / 2 > s) return cout << "NO\n", void();
    if (n == k && 1ll * k * (k - 1) / 2 != s) return cout << "NO\n", void();
    if (n == k + 1 && 1ll * (k + 1) * k / 2 == s) return cout << "NO\n", void();
    cout << "YES\n";
    for (int i = 0; i < k; i ++ ) 
        cout << i << " ", s -= i;
    if (s != k) cout << s << " ", n --;
    else cout << 1 << " " << k - 1 << " ", n -= 2;
    n -= k;
    for (int i = 1; i <= n; i ++ ) 
        cout << 0 << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
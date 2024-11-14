#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, k; cin >> n >> k;
    vector<array<i64, 2>> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        i64 c, w, f; cin >> c >> w >> f;
        if (w == 2) c <<= 1;
        a[i][0] = f, a[i][1] = c;
    }
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return a[i][0] > a[j][0];
    });
    i64 lst = 0, ans = 0, sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        auto [f, c] = a[b[i]];
        if (lst) {
            i64 t = min(c, k - lst);
            lst = (lst + t) % k, c -= t;
        }
        if (!c) continue;
        ans += ((c + k - 1) / k) * f;
        lst = (lst + c % k) % k;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
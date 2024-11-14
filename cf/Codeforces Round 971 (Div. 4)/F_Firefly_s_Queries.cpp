#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<i64> w(n << 1 | 1);
    for (int i = 1; i <= n; i ++ )
        cin >> w[i], w[i + n] = w[i];
    vector<i64> pre(n << 1 | 1);
    for (int i = 1; i <= (n << 1); i ++ ) 
        pre[i] = pre[i - 1] + w[i];
    function<i64(i64)> check = [&] (i64 l) {
        i64 ans = l / n * pre[n];
        i64 t = (l / n) % n;
        return ans + pre[t + l % n] - pre[t];
    };
    while (q -- ) {
        i64 l, r; cin >> l >> r;
        cout << check(r) - check(l - 1) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
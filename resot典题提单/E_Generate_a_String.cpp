#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> f(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        f[i] = f[i - 1] + x;
        if (!(i & 1)) f[i] = min(f[i], f[i >> 1] + y);
        else f[i] = min({f[i], f[i >> 1] + y + x, f[(i + 1) >> 1] + y + x});
    }
    cout << f[n] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    while (T -- ) solve();
    return 0;
}
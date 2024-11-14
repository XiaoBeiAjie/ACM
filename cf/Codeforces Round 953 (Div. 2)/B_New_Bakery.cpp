#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n, a, b; cin >> n >> a >> b;
    if (b <= a) return cout << n * a << "\n", void(); 
    i64 t = (b - a);
    if (t <= n) cout << (b + a + 1) * t / 2 + (n - t) * a << "\n";
    else cout << (b + b + 1 - n) * n / 2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
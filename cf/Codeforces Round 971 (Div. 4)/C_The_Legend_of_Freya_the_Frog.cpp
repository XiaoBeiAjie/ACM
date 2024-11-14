#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int t1 = (x + k - 1) / k, t2 = (y + k - 1) / k;
    if (t1 > t2) cout << 2ll * t1 - 1 << "\n";
    else cout << 2ll * t2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
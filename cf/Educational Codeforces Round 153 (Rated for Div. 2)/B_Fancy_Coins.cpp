#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll m, k, a1, a2;
    cin >> m >> k >> a1 >> a2;
    ll res1 = min(m / k, a2);
    m -= res1 * k;
    if (m - a1 <= 0) return cout << "0\n", void();
    ll r1 = m / k;
    m -= r1 * k;
    if (m >= a1) cout << r1 + m - a1 << "\n";
    else cout << r1 - (a1 - m) / k << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
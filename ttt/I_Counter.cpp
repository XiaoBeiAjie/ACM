#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
void solve() {
    int n, m; cin >> n >> m;
    map<int, int> mp;
    bool ok = true;
    for (int i = 1; i <= m; i ++ ) {
        int x, y; cin >> x >> y;
        if (mp.find(x) != mp.end() && mp[x] != y) ok = false;
        mp[x] = y;
    }
    if (m > n) return cout << "\n", void();
    int lx = 0, ly = 0;
    for (auto [x, y] : mp) {    
        int _ok = false;
        if (x - lx == y - ly) _ok = true;
        if (x - lx >= y + (ly != 0)) _ok = true;
        if (!_ok) ok = false;
        lx = x, ly = y;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
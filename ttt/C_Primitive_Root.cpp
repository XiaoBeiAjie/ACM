#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve() {
    i64 p_, m_; cin >> p_ >> m_;
    if (p_ == 2) return cout << ((m_ >> 1) + 1) << "\n", void();
    __int128_t p = p_, m = m_;
    i64 k = (m + 1) / p;
    i64 ans = k + 1;
    for (int i = k + 1; i <= k + 1000; i ++ ) 
        if (((i * p + 1) ^ (p - 1)) <= m) 
            ans ++;
    for (int i = k; i >= max(0ll, k - 1000); i -- ) 
        if (((i * p + 1) ^ (p - 1)) > m) 
            ans --;
    cout << ans << "\n";
}
 
signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
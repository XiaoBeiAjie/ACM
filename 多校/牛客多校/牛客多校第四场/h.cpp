#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> w (n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin() + 1, w.end());
    if (n == 1) return cout << 0 << "\n", void();
    ll ans = 1e18;
    for (int i = 1; i < n; i ++ ) 
        ans = min(ans, w[i + 1] - w[i]);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
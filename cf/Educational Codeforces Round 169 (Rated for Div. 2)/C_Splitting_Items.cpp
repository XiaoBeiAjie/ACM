#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin() + 1, w.end(), greater<int>());
    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
        int res = min(k, w[i - 1] - w[i]);
        k -= res; w[i] += res;
        ans += w[i - 1] - w[i];
    }
    cout << ans + (n & 1 ? w[n] : 0) << "\n";
        
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
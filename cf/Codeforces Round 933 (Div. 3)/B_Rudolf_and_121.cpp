#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 2; i < n; i ++ ) {
        w[i] -= 2ll * w[i - 1];
        w[i + 1] -= w[i - 1];
        w[i - 1] = 0;
        if (w[i] < 0 || w[i + 1] < 0) return cout << "No\n", void();
    }
    if (count(w.begin() + 1, w.end(), 0) != n) cout << "No\n";
    else cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
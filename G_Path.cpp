#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    i64 ans = 0;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> v(m + 1);
    for (int i = 1; i <= m; i ++ ) 
        cin >> v[i];
    for (int i = 1; i < n; i ++ ) 
        ans += abs(w[i + 1] - w[i]);
    for (int i = 1; i < m; i ++ ) 
        ans += abs(v[i + 1] - v[i]);
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    while (T -- ) solve();
    return 0;
}
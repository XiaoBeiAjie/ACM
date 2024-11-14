#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i][0] >> w[i][1] >> w[i][2];
    vector f(n + 1, array<i64, 3>({0}));
    for (int i = 1; i <= n; i ++ ) {
        f[i][0] = max(f[i - 1][1], f[i - 1][2]) + w[i][0];
        f[i][1] = max(f[i - 1][0], f[i - 1][2]) + w[i][1];
        f[i][2] = max(f[i - 1][1], f[i - 1][0]) + w[i][2];
    }
    cout << max({f[n][0], f[n][1], f[n][2]}) << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
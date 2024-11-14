#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = pre[i - 1] + a[i];
    vector f(n + 1, vector<i64>(n + 1));
    for (int i = 1; i <= n; i ++ ) 
        f[i][i] = a[i];
    for (int len = 2; len <= n; len ++ ) 
        for (int l = 1; l + len - 1 <= n; l ++ ) {
            int r = l + len - 1;
            f[l][r] = max(f[l + 1][r], f[l][r - 1]) + pre[r] - pre[l - 1];
        }
    cout << f[1][n] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
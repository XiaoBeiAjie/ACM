#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector f(n + 1, vector<int> (301));
    for (int i = n; i; i -- ) 
        for (int k = 1; k <= 300; k ++ ) 
            if (i + w[i] + k > n) f[i][k] = 1;
            else f[i][k] = f[i + w[i] + k][k] + 1;
    int q; cin >> q;
    while (q -- ) {
        int p, k; cin >> p >> k;
        if (k <= 300) {
            cout << f[p][k] << "\n";
            continue;
        }
        int cnt = 0;
        while (p <= n) {
            p = p + w[p] + k;
            cnt ++;
        }
        cout << cnt << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
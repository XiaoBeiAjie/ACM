#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> r(m + 1), c(m + 1);
    for (int i = 1; i <= m; i ++ ) 
        cin >> r[i] >> c[i];
    vector<int> b(m + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return r[i] < r[j];
    });
    constexpr i64 inf = 0x3f3f3f3f;
    i64 p = 0, minn = inf, idx = 0;
    for (int i = 1; i <= m; i ++ ) {
        while (p < r[b[i]]) {
            p ++;
            if (minn > w[p]) idx = p, minn = w[p];
        }  
        w[idx] -= c[b[i]];
        minn -= c[b[i]];
    }
    sort(w.begin() + 1, w.end());
    for (int i = 1; i <= n; i ++ ) 
        w[i] += w[i - 1], cout << w[i] << " \n"[i == n];
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
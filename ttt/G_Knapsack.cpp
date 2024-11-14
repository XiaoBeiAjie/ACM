#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<array<int,2>> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i][0] >> a[i][1];
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        if (a[i][0] == a[j][0]) 
            return a[i][1] > a[j][1];
        return a[i][0] > a[j][0];
    });
    vector f(n + 2, vector<i64>(m + 1));
    for (int i = n; i; i -- ) 
        for (int j = m; j >= 0; j -- ) {
            f[i][j] = f[i + 1][j];
            if (j >= a[b[i]][0]) f[i][j] = max(f[i][j], f[i + 1][j - a[b[i]][0]] + a[b[i]][1]);
        }
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    i64 res = 0, ans = 0;
    ans = *max_element(f[1].begin(), f[1].end());
    if (!k) return cout << ans << "\n", void();
    for (int i = 1; i <= n; i ++ ) {
        if (pq.size() < k) {
            pq.push(a[b[i]][1]);
            res += a[b[i]][1];
            i64 t = 0;
            if (i != n) 
                t = *max_element(f[i + 1].begin(), f[i + 1].end());
            ans = max(ans, res + t);
            continue;
        }
        if (pq.top() < a[b[i]][1]) {
            res -= pq.top();
            pq.pop();
            pq.push(a[b[i]][1]);
            res += a[b[i]][1];
            i64 t = 0;
            if (i != n) 
                t = *max_element(f[i + 1].begin(), f[i + 1].end());
            ans = max(ans, res + t);
            continue;
        }
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
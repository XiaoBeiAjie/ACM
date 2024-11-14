#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<i64> w(n + 1);
    set<i64> s;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        if (s.find(w[i]) == s.end()) 
            s.insert(w[i]);
    }
    i64 ans = 0;
    for (auto u : s) {
        i64 l = u, r = u + m;
        i64 res = 0;
        for (int i = 1; i < n; i ++ ) {
            i64 x = min(max(l, w[i]), r), y = min(max(l, w[i + 1]), r);
            res += abs(y - x);
        }
        ans = max(res, ans);
    }
    for (auto u : s) {
        i64 r = u, l = u - m;
        i64 res = 0;
        for (int i = 1; i < n; i ++ ) {
            i64 x = min(max(l, w[i]), r), y = min(max(l, w[i + 1]), r);
            res += abs(y - x);
        }
        ans = max(res, ans);
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
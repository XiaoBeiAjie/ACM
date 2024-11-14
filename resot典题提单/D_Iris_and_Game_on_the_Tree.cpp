#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector e(n + 1, vector<int> ());
    vector<int> d(n + 1);
    for (int i = 1; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
        d[u] ++, d[v] ++;
    }
    string s; cin >> s;
    s = " " + s;
    int cnt = 0, fst = 0, cnt1 = 0, cnt2 = 0, idx = 0;
    for (int i = 2; i <= n; i ++ ) {
        if (d[i] != 1) {
            if (s[i] == '?') idx ++;
            continue;
        }
        if (s[i] == '?') cnt ++;
        else if (s[i] == '1') cnt1 ++;
        else cnt2 ++;
    }
    if (s[1] == '?') {
        if (idx & 1) cout << max(min(cnt1, cnt2) + (cnt + 1) / 2, max(cnt1, cnt2) + cnt / 2) << "\n";
        else cout << max(cnt1, cnt2) + cnt / 2 << "\n";
    }
    else if (s[1] == '1') cout << cnt2 + (cnt + 1) / 2 << "\n";
    else cout << cnt1 + (cnt + 1) / 2 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
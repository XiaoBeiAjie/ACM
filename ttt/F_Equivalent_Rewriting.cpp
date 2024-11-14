#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    vector pos(n + 1, vector<int>());
    vector<int> dist(n + 1);
    vector t(n + 1, stack<int>());
    int maxx = 0;
    for (int i = 1; i <= n; i ++ ) {
        int len; cin >> len;
        for (int j = 1; j <= len; j ++ ) {
            int x; cin >> x;
            pos[i].push_back(x);
            dist[i] = max(dist[i], dist[a[x]] + 1);
            a[x] = i;
        }
        t[dist[i]].push(i);
        maxx = max(maxx, dist[i]);
    }
    vector<int> ans;
    bool flag = false;
    for (int i = 1; i < n; i ++ ) {
        bool ok = true;
        for (int j = 0; j < pos[i].size(); j ++ ) 
            if (a[pos[i][j]] == i + 1) 
                ok = false;
        if (ok) ans.push_back(i + 1), ans.push_back(i), i ++, flag = true;
        else ans.push_back(i);
    }
    if (ans.size() == n - 1) ans.push_back(n);
    if (!flag) return cout << "No\n", void();
    cout << "Yes\n";
    for (int i = 0; i < n; i ++ ) 
        cout << ans[i] << " \n"[i == n - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
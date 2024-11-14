#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> w(n + 1);
    vector<int> cnt(14);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], cnt[w[i]] ++;
    sort(cnt.begin() + 1, cnt.end());
    vector<int> v(14);
    int ans = 13;
    function<void(int)> dfs = [&] (int t) {
        if (t == 14) {
            int res = 0;
            for (int i = 1; i <= 13; i ++ ) 
                if (v[i]) res ++;
            return ans = min(ans, res), void();
        }
        bool ok = false;
        for (int i = 1; i <= 13; i ++ ) {
            if (ok) break;
            if (i >= ans) return ;
            if (!v[i]) {
                ok = true;
                v[i] += cnt[t];
                dfs(t + 1);
                v[i] -= cnt[t];
            }
            else if (v[i] + cnt[t] <= k) {
                v[i] += cnt[t];
                dfs(t + 1);
                v[i] -= cnt[t];
            }
        }
    };
    dfs(1);
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
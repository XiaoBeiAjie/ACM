#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s; cin >> s;
    s = " " + s;
    vector<int> pre(n + 1), pos(n + 1);
    int idx = 0;
    for (int i = 1; i <= n; i ++ ) {
        pos[i] = idx;
        idx = (s[i] == '0') ? i : idx;
        pre[i] = pre[i - 1] + (s[i] == '0');
    }
    constexpr int inf = 0x3f3f3f3f;
    function<bool(int)> check = [&] (int mid) {
        vector f(n + 1, vector<int> (k + 1, inf));
        f[0][0] = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= k; j ++ ) {
                f[i][j] = f[i - 1][j];
                if (i >= mid && j) {
                    int idx = pos[i - mid + 1];
                    f[i][j] = min(f[max(idx - 1, 0)][j - 1] + pre[i] - pre[idx], f[i][j]);
                }
            }
        }
        return f[n][k] <= m;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (!check(l)) l = -1;
    cout << l << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
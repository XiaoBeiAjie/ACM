#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], pos[w[i]] = i;
    constexpr int inf = 0x3f3f3f3f;
    vector f_max(30, vector<int>(n + 1, 0));
    vector f_min(30, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i ++ ) 
        f_max[0][i] = w[i], f_min[0][i] = w[i];
    for (int j = 1; j <= __lg(n); j ++ ) 
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) 
            f_max[j][i] = max(f_max[j - 1][i], f_max[j - 1][i + (1 << (j - 1))]),
            f_min[j][i] = min(f_min[j - 1][i], f_min[j - 1][i + (1 << (j - 1))]);
    function<int(int, int)> query_min = [&] (int l, int r) {
        int k = __lg(r - l + 1);
        return min(f_min[k][l], f_min[k][r - (1 << k) + 1]);
    };
    function<int(int, int)> query_max = [&] (int l, int r) {
        int k = __lg(r - l + 1);
        return max(f_max[k][l], f_max[k][r - (1 << k) + 1]);
    };
    function<int(int, int)> check = [&] (int l, int r) {
        if (l == r) return 0;
        int minn = query_min(l, r), maxx = query_max(l, r);
        int pos_l = min(pos[minn], pos[maxx]), pos_r = max(pos[minn], pos[maxx]);
        return check(l, pos_l) + 1 + check(pos_r, r);
    };
    cout << check(1, n) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
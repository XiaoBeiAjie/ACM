#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> w(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        int a, b, c; cin >> a >> b >> c;
        w[i][0] = a - b, w[i][1] = a, w[i][2] = c;
        sum += b;
    }
    function<bool(i64)> check = [&] (i64 mid) {
        vector<long double> e(n + 1);
        for (int i = 1; i <= n; i ++ ) 
            e[i] = 1.0 * mid / w[i][2] - sum - w[i][1];
        vector<int> b(n + 1);
        iota(b.begin(), b.end(), 0);
        sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
            if (w[i][0] < 0 && w[j][0] < 0) 
                return e[i] > e[j];
            if (w[i][0] < 0) 
                return true;
            else if (w[j][0] < 0) 
                return false;
            return w[i][0] + e[i] < w[j][0] + e[j];
        });
        i64 pre = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (pre > e[b[i]]) 
                return false;
            pre += w[b[i]][0];
        }
        return true;
    };
    i64 lo = 0, hi = 2e17;
    while (lo < hi) {
        i64 mid = lo + hi >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    vector<long double> e(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        e[i] = 1.0 * lo / w[i][2] - sum - w[i][1];
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        if (w[i][0] < 0 && w[j][0] < 0) 
            return e[i] > e[j];
        if (w[i][0] < 0) 
            return true;
        else if (w[j][0] < 0) 
            return false;
        return w[i][0] + e[i] < w[j][0] + e[j];
    });
    for (int i = 1; i <= n; i ++ )
        cout << b[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> tr(n + 1);
    function<int(int)> lowbit = [&] (int x) {
        return x & -x;
    };
    function<void(int, int)> update = [&] (int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) 
            tr[i] += c;
    };
    function<i64(int)> query = [&] (int x) {
        i64 res = 0;
        for (int i = x; i; i -= lowbit(i)) 
            res += tr[i];
        return res;
    };
    vector<int> w(n + 1);
    vector<array<int, 2>> b(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        w[i] = min(w[i], n);
        b[i][0] = w[i], b[i][1] = i;
    }
    i64 ans = 0;
    sort(b.begin() + 1, b.end(), greater<array<int, 2>>());
    for (int i = n, j = 1; i; i -- ) {
        while (j <= n && b[j][0] >= i) {
            update(b[j][1], 1);
            j ++;
        } 
        if (w[i] <= i) continue;
        ans += query(w[i]) - query(i);
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
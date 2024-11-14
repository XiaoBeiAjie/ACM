#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    int n; cin >> n;
    vector<i64> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = pre[i - 1] + w[i];
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        s[i] = s[i - 1] + pre[i];
    vector<i64> ss(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        ss[i] = s[n] - s[i - 1] - (n - i + 1) * pre[i - 1];
    vector<i64> sss(n + 1);
    for (int i = 1; i <= n; i ++ )  
        sss[i] = sss[i - 1] + ss[i];
    vector<i64> d(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        d[i] = d[i - 1] + (n - i + 1);
    function<i64(i64 x)> query = [&] (i64 x) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + hi + 1 >> 1;
            if (d[mid] <= x) lo = mid;
            else hi = mid - 1;
        }
        int u = lo;
        i64 res = 0;
        res += sss[u];
        x -= d[u];
        res += s[u + x] - s[u] - x * pre[u];
        return res;
    };
    int q; cin >> q;
    while (q -- ) {
        i64 l, r; cin >> l >> r;
        cout << query(r) - query(l - 1) << "\n";
    }
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T = 1;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}
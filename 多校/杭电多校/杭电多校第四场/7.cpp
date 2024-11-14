#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    ll ans = 0; int maxx = 0;
    for (int i = 0; i < n; i ++ ) 
        cin >> a[i], ans += a[i];
    for (int i = 0; i < n; i ++ )
        cin >> b[i], maxx = max(maxx, b[i]);
    for (int k = 1; k <= 2004; k ++ ) {
        if (k > q) return ;
        int t; cin >> t;
        for (int i = 0; i < n; i ++ ) 
            if (a[i] < b[(i + t) % n])
                ans -= a[i], ans += a[i] = b[(i + t) % n];
        cout << ans << "\n";
    }
    q -= 2004;
    int idx = 990000000;
    vector<pair<int, int>> pa, pb;
    for (int i = 0; i < n; i ++ ) 
        if (a[i] < idx) pa.push_back({i, a[i]});
    for (int i = 0; i < n; i ++ ) 
        if (b[i] >= idx) pb.push_back({-b[i], i});
    sort(pb.begin(), pb.end());
    while (q -- ) {
        int t; cin >> t;
        for (auto [i, y] : pa) {
            if (a[i] < b[(i + t) % n])
                ans -= a[i], ans += a[i] = b[(i + t) % n];
        }
        int cnt = 0;
        for (auto [y, i] : pb) {
            if (cnt >= 3004) break;
            if (a[(i - t + n) % n] < b[i])
                ans -= a[(i - t + n) % n], ans += a[(i - t + n) % n] = b[i];
            cnt ++;
        } 
        cout << ans << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
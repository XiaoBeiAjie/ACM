#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int i = 1; i <= n; i ++ )
        cin >> b[i];
    ll ans = 0;
    auto check = [&] (ll mid) {
        ll res = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] >= mid) res += (a[i] - mid) / b[i] + 1;
            if (res > k) return false;
        }
        return true;
    };
    ll l = 1, r = 1000000001;
    while (l < r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    //cout << l << " " << endl;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] < l) continue;
        ll res = (a[i] - l) / b[i] + 1;
        ans += a[i] * res - (res - 1) * res * b[i] / 2;
        k -= res;
        a[i] = max(0ll, a[i] - res * b[i]);
    }
    priority_queue<array<int, 2>> q;
    for (int i = 1; i <= n; i ++ ) 
        q.push({a[i], - b[i]});
    while (k -- ) {
        auto [x, y] = q.top();
        if (x == 0) break;
        q.pop();
        ans += x;
        x = max(x + y, 0);
        q.push({x, y});
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
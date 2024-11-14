#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    a = " " + a, b = " " + b;
    function<pair<int, int>(int)> check = [&] (int idx) {
        if (a[idx] == '1') return make_pair(idx, idx);
        int l = -1, r = -1;
        if (idx > 1 && b[idx - 1] == '1') l = idx - 1;
        else if (idx > 2 && a[idx - 2] == '0') l = idx - 2;
        if (idx < n && b[idx + 1] == '1') r = idx + 1;
        else if (idx < n - 1 && a[idx + 2] == '0') r = idx + 2;
        if (!~l) r = -1;
        if (!~r) l = -1;
        return make_pair(l, r);
    };
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = pre[i - 1] + (check(i).first != -1);
    int q; cin >> q;
    while (q -- ) {
        int l, r; cin >> l >> r;
        if (r - l <= 3) {
            int cnt = 0;
            for (int i = l; i <= r; i ++ ) {
                auto [l_, r_] = check(i);
                if (l_ >= l && r_ <= r) cnt ++;
            }
            cout << cnt << "\n";
            continue;
        }
        int cnt = pre[r] - pre[l - 1];
        for (auto i : {l, l + 1, r - 1, r}) {
            auto [l_, r_] = check(i);
            if (~l_ && (l_ < l || r_ > r)) cnt --;
        }
        cout << cnt << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
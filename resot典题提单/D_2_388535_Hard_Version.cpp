#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    int idx = 0;
    vector tr(n * 20, array<int, 2>());
    function<void(int)> insert = [&] (int x) {
        int p = 0;
        for (int i = 16; i >= 0; i -- ) {
            int u = (x >> i) & 1;
            if (!tr[p][u]) tr[p][u] = ++ idx;
            p = tr[p][u]; 
        }
    };
    function<bool(int)> query = [&] (int x) {
        int p = 0, maxx = 0, minn = 0;
        for (int i = 16; i >= 0; i -- ) {
            int u = (x >> i) & 1;
            if (tr[p][u ^ 1]) {
                p = tr[p][u ^ 1];
                maxx |= (1 << i);
            }
            else 
                p = tr[p][u];
        }
        p = 0;
        for (int i = 16; i >= 0; i -- ) {
            int u = (x >> i) & 1;
            if (tr[p][u]) 
                p = tr[p][u];
            else {
                p = tr[p][u ^ 1];
                minn |= (1 << i);
            }
        }
        return (minn == l && maxx == r);
    };
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], insert(w[i]);
    for (int i = 1; i <= n; i ++ ) {
        int t = w[i] ^ l;
        if (!query(t)) 
            continue;
        cout << t << "\n";
        break;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
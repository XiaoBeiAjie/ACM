#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), p(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> p[i];
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return w[i] > w[j];
    });
    ll ans = 0; int num = 0, idx = 1;
    vector<bool> vis(n + 1), st(n + 1);
    for (int k = 1; k <= n; k ++ ) {
        vis[p[k - 1]] = true;
        int cnt = 1 + st[p[k - 1]];
        while (idx <= n && cnt) {
            if (!vis[b[idx]]) cnt --, st[b[idx]] = true;
            if (!cnt) break;
            idx ++;
        }
        //cerr << k << " " << idx << "\n";
        if (idx <= n && ans < 1ll * k * w[b[idx]]) ans = 1ll * k * w[b[idx]], num = k;
        idx ++;
    }
    cout << ans << " " << num << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
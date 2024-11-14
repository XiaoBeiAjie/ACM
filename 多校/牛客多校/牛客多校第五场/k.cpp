#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 2e15;

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    int idx = 30;
    vector f(n + 1, vector (n + 1, vector<ll> (2 * idx + 1, -1)));
    function<ll(int, int, int)> dfs = [&] (int l, int r, int c) {
        if (abs(c) > idx) return inf;
        if (l > r) return 0ll;
        if (l == r) return w[l] * c;
        if (f[l][r][c + idx] != -1) return f[l][r][c + idx]; 
        ll tl = w[l], tr = w[r], res = inf;
        while (tl <= tr) {
            //cerr << "<<" << l << " " << r << " " << tl << " " << tr << "\n";
            ll mid = tl + tr >> 1;
            int p = lower_bound(w.begin(), w.end(), mid) - w.begin();
            //cerr << p << " " << f[l][p - 1][c - 1] << " " << f[p][r][c + 1] << "\n";
            //cerr << p << "!!!\n";
            ll resl = dfs(l, p - 1, c - 1) + mid;
            ll resr = dfs(p, r, c + 1) - mid;
            if (resl > resr) tr = mid - 1;
            else tl = mid + 1;
            res = min(res, max(resl, resr));
        }
        f[l][r][c + idx] = res;
        return res;
    };
    cout << dfs(1, n, 0) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
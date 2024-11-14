#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], sum += w[i];
    sort(w.begin(), w.end());
    if (sum & 1) return cout << "-1\n", void();
    sum >>= 1;
    vector<int> f(sum + 1);
    f[0] = 1;
    vector<int> p(sum + 1), pos(sum + 1);
    for (int i = 1; i <= n; i ++ ) {
        auto g = f;
        for (int j = sum; j >= w[i]; j -- ) 
            if (f[j - w[i]] && !g[j]) g[j] = 1, p[j] = j - w[i], pos[j] = i;
        f = move(g);
    }
    if (!f[sum]) return cout << "-1\n", void();
    vector<int> a, b;
    for (int i = pos[sum] + 1; i <= n; i ++ ) 
        b.push_back(w[i]);
    int idx = pos[sum], res = sum;
    while (idx) {
        a.push_back(w[idx]);
        for (int i = pos[p[res]] + 1; i < idx; i ++ ) 
            b.push_back(w[i]);
        res = p[res]; idx = pos[res];
    }
    int sum1 = 0, sum2 = 0, i = 0, j = 0;
    vector<int> ans(n + 1);
    for (int t = 1; t <= n; t ++ ) {
        if (sum1 <= sum2) ans[t] = a[i], sum1 += a[i ++];
        else ans[t] = b[j], sum2 += b[j ++]; 
    }
    for (int i = 1; i <= n; i ++ ) 
        cout << ans[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
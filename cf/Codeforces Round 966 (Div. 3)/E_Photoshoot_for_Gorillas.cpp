#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w; cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i ++ ) 
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<ll> g;
    vector<ll> col(m + 2), row(n + 2);
    for (int i = 1; i + k - 1 <= n; i ++ ) 
        row[i] += 1, row[i + k] -= 1; 
    for (int i = 1; i <= n; i ++ ) 
        row[i] += row[i - 1];
    for (int i = 1; i + k - 1 <= m; i ++ ) 
        col[i] += 1, col[i + k] -= 1;
    for (int i = 1; i <= m; i ++ ) 
        col[i] += col[i - 1];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            g.push_back(col[j] * row[i]);
    sort(g.begin(), g.end(), greater<ll>());
    ll sum = 0;
    for (int i = 0; i < w; i ++ ) 
        sum += g[i] * a[i];
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
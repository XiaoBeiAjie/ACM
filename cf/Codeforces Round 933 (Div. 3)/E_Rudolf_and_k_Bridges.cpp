#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector w(n + 1, vector<ll> (m + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cin >> w[i][j], w[i][j] ++;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        vector<ll> g(m + 1);
        deque<int> dq;
        for (int j = 1; j <= m; j ++ ) {
            while (!dq.empty() && dq.front() + d + 1 < j) dq.pop_front();
            g[j] = w[i][j] + (dq.empty() ? 0 : g[dq.front()]);
            while (!dq.empty() && g[dq.back()] >= g[j]) dq.pop_back();
            dq.push_back(j);
        }
        pre[i] += g[m] + pre[i - 1];
    }
    ll sum = LLONG_MAX;
    for (int i = k; i <= n; i ++ ) 
        sum = min(sum, pre[i] - pre[i - k]);
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
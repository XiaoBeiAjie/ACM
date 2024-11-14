#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1);
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], pre[i] += w[i] + pre[i - 1];
    int maxx = *max_element(w.begin() + 1, w.end());
    maxx = max(w[1] + m, maxx);
    int idx = maxx == w[1] + m ? 1 : find(w.begin() + 1, w.end(), maxx) - w.begin();
    for (int i = 1; i <= n; i ++ ) {
        if (i == idx) {
            cout << "0 ";
            continue;
        }
        if (w[i] + m + pre[i - 1] >= maxx) cout << i - 1 << " ";
        else cout << i << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
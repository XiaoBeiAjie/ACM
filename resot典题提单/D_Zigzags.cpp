#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> pre(n + 1);
    pre[w[1]] ++;
    i64 ans = 0; 
    for (int i = 2; i <= n - 2; i ++ ) {
        vector<int> suf(n + 1);
        for (int j = i + 1; j <= n; j ++ ) suf[w[j]] ++;
        for (int j = i + 1; j <= n - 1; j ++ ) {
            suf[w[j]] --;
            ans += 1ll * pre[w[j]] * suf[w[i]];
        } 
        pre[w[i]] ++;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
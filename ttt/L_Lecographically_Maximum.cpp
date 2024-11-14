#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    vector<int> cnt(30);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 0; j < 30; j ++ ) 
            if ((w[i] >> j) & 1) cnt[j] ++;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 0; j < 30; j ++ ) 
            if (cnt[j]) ans[i] += (1 << j), cnt[j] -- ;
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
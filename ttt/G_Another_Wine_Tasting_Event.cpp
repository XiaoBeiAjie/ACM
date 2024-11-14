#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> pre(n << 1);
    for (int i = 1; i < (n << 1); i ++ ) 
        pre[i] = pre[i - 1] + (s[i] == 'W');
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, pre[i + n - 1] - pre[i - 1]);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
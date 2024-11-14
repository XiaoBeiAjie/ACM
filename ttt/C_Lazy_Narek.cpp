#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> s[i], s[i] = " " + s[i];
    function<int(char)> fun = [&] (char c) {
        if (c == 'n') return 0;
        if (c == 'a') return 1;
        if (c == 'r') return 2;
        if (c == 'e') return 3;
        if (c == 'k') return 4;
        return -1;
    };
    constexpr int inf = 0x3f3f3f3f;
    vector<int> f(5, -inf);
    f[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        auto g = f;
        for (int k = 0; k < 5; k ++ ) {
            int s1 = 0, s2 = 0, idx = k;
            for (int j = 1; j <= m; j ++ ) {
                int c = fun(s[i][j]);
                if (c == -1) continue;
                if (c == idx) s1 ++, idx = (idx + 1) % 5;
                else s2 ++;
            }
            g[idx % 5] = max(g[idx % 5], f[k] + (s1 + k % 5) / 5 * 5 - s2);
        }
        f = move(g);  
    }
    int ans = 0;
    for (int i = 0; i < 5; i ++ ) 
        ans = max(ans, f[i] - i);
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
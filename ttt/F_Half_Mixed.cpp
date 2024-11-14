#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;

i64 A[N];

void solve() {
    i64 n, m; cin >> n >> m;
    if ((((n + 1) * n / 2) * (m * (m + 1) / 2)) & 1) return cout << "No\n", void();
    vector g(n + 1, vector<i64> (m + 1));
    vector<int> ans(max(n, m) + 1);
    function<void(int)> fun = [&] (int len) {
        int c = 0;
        int j = len, sum = 0;
        i64 need = 1ll * len * (len + 1) / 4;
        while (sum < len) {
            while (len - sum - j + A[j] > need) j --;
            for (int i = sum + 1; i <= sum + j; i ++ ) 
                ans[i] = c;
            c ^= 1, sum += j, need -= A[j];
        }
    };
    if ((n % 4) == 0 || (n % 4 == 3)) {
        fun(n);
        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= m; j ++ ) 
                g[i][j] = ans[i];
    } else {
        fun(m);
        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= m; j ++ ) 
                g[i][j] = ans[j];
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cout << g[i][j] << " \n"[j == m];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 1000000; i ++ ) 
        A[i] = 1ll * i * (i + 1) / 2;
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1030;
typedef long long LL;

int t, m, s;
LL f[2][N];

void solve() {
    cin >> m >> s >> t;
    for (int i = 0; i <= m + 10; i ++ ) f[0][i] = -0x3f3f3f3f;
    f[0][m] = 0;
    for (int i = 1; i <= t; i ++ ) 
        for (int j = 0; j <= m + 10; j ++ ) {
            f[i & 1][j] = f[i & 1 ^ 1][j] + 17;
            if (j + 10 <= m + 10) f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j + 10] + 60);
            if (j >= 4) f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j - 4]);
            if (f[i & 1][j] >= s) return cout << "Yes\n" << i << endl, void(); 
        }
    LL ans = 0;
    for (int i = 0; i <= m; i ++ ) 
        ans = max(ans, f[t & 1][i]);
    cout << "No\n" << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
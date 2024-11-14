#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int m = s.size();
    s = " " + s;
    vector<int> ne(m + 1);
    function<void()> kmp = [&] () {
        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[j + 1] == s[i]) j ++;
            ne[i] = j;
        }
    };
    kmp();
    vector nxt(m + 1, vector<int>(26));
    for (int i = 0; i < m; i ++ ) 
        for (int j = 0; j < 26; j ++ ) {
            int t = i;
            while (t && s[t + 1] != j + 'a') t = ne[t];
            if (s[t + 1] == j + 'a') nxt[i][j] = t + 1;
            else nxt[i][j] = 0;
        }

    constexpr int mod = 998244353;
    vector f(n + 1, vector(k + 1, vector<i64>(m + 1)));
    f[0][0][0] = 1;
    for (int i = 0; i < n; i ++ ) 
        for (int j = 0; j <= k && j * m <= i; j ++ ) 
            for (int l = 0; l < m; l ++ )
                for (int c = 0; c < 26; c ++ ) {
                    int nxt_j = j, nxt_l = nxt[l][c];
                    if (nxt_l == m) nxt_l = 0, nxt_j ++;
                    if (nxt_j <= k) 
                        f[i + 1][nxt_j][nxt_l] = (f[i + 1][nxt_j][nxt_l] + f[i][j][l]) % mod;
                }
            
        
    
    i64 ans = 0;
    for (int i = 0; i < m; i ++ ) 
        ans = (ans + f[n][k][i]) % mod;
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    constexpr int inf = 0x3f3f3f3f;
    vector f(n + 1, vector<int> (n * n + 1, inf));
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        vector g(n + 1, vector<int> (n * n + 1, inf));
        for (int j = 0; j < i; j ++ ) 
            for (int k = 0; k <= j * (i - j); k ++ ) {
                g[j + 1][k] = min(g[j + 1][k], f[j][k] + (s[i] != '0'));
                g[j][k + j] = min(g[j][k + j], f[j][k] + (s[i] != '1'));
            }
        f = move(g);
    }
    int cnt = count(s.begin(), s.end(), '0');
    // 换0和换1重复计算
    cout << (f[cnt][cnt * (n - cnt) >> 1] >> 1) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
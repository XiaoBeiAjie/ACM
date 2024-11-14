#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1, s2 = " " + s2;
    map<char, int> mp;
    mp['A'] = 0, mp['T'] = 1, mp['G'] = 2, mp['C'] = 3;
    vector<array<int, 4>> d(4);
    for (int i = 0; i < 4; i ++ ) 
        for (int j = 0; j < 4; j ++ ) 
            cin >> d[i][j];
    int a, b;
    cin >> a >> b;
    int len = max(m, n);
    vector f(len + 1, vector (len + 1, vector<int> (3)));
    for (int i = 1; i <= len; i ++ ) {
        f[0][i][2] = f[i][0][1] = -0x3f3f3f3f;
        f[0][i][0] = f[i][0][0] = -0x3f3f3f3f;
        f[0][i][1] = f[i][0][2] = -a - b * (i - 1);
    }
    f[0][0][1] = f[0][0][2] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) {
            f[i][j][0] = max({f[i - 1][j - 1][0], f[i - 1][j - 1][1], f[i - 1][j - 1][2]}) + d[mp[s1[i]]][mp[s2[j]]];
            f[i][j][1] = max({f[i][j - 1][0] - a, f[i][j - 1][1] - b, f[i][j - 1][2] - a});
            f[i][j][2] = max({f[i - 1][j][0] - a, f[i - 1][j][1] - a, f[i - 1][j][2] - b});
        }
    cout << max({f[n][m][0], f[n][m][1], f[n][m][2]}) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
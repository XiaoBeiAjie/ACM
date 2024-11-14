#include <bits/stdc++.h>
using namespace std;
const int N = 510;
typedef long long LL;

int n, m, k;
LL w[N][N];
int v[N][N];
string s[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cin >> w[i][j];
    for (int i = 1; i <= n; i ++ ) 
        cin >> s[i], s[i] = " " + s[i];
    LL e = 0;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            if (s[i][j] == '1') e += w[i][j];
            else e -= w[i][j];
    if (e < 0) e = -e;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + (s[i][j] == '1' ? 1 : -1);
    LL tt = 0;
    for (int i = k; i <= n; i ++ ) 
        for (int j = k; j <= m; j ++ ) {
            LL t = abs(v[i][j] - v[i - k][j] - v[i][j - k] + v[i - k][j - k]);
            tt = __gcd(tt, t);
        }
    if (tt == 0) {
        if (e) cout << "No" << endl;
        else cout << "Yes" << endl;
    } 
    else if (e % tt == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
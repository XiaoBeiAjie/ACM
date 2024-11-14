#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    vector cnta(n + 1, vector<int> (26)), cntb(n + 1, vector<int> (26));
    for (int i = 1; i <= n; i ++ ) {
        cnta[i][a[i] - 'a'] = 1;
        for (int j = 0; j < 26; j ++ ) 
            cnta[i][j] += cnta[i - 1][j];
    }
    for (int i = 1; i <= n; i ++ ) {
        cntb[i][b[i] - 'a'] = 1;
        for (int j = 0; j < 26; j ++ ) 
            cntb[i][j] += cntb[i - 1][j];
    }
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for (int i = 0; i < 26; i ++ ) 
            res += abs(cnta[r][i] - cnta[l - 1][i] - (cntb[r][i] - cntb[l - 1][i]));
        cout << res / 2 << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
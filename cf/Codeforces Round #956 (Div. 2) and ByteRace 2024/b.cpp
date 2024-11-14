#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s1(n + 1), s2(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> s1[i], s1[i] = " " + s1[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> s2[i], s2[i] = " " + s2[i];
    vector a(n + 1, vector<int> (m + 1));
    vector b(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ )
            a[i][j] = s1[i][j] - '0';
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            b[i][j] = s2[i][j] - '0';
    for (int i = 1; i <= n; i ++ ) {
        int res = 0;
        for (int j = 1; j <= m; j ++ ) 
            res += (b[i][j] + 3 - a[i][j]);
        if (res % 3 != 0) return cout << "No\n", void(); 
    }
    for (int j = 1; j <= m; j ++ ) {
        int res = 0;
        for (int i = 1; i <= n; i ++ ) 
            res += (b[i][j] + 3 - a[i][j]);
        if (res % 3 != 0) return cout << "No\n", void(); 
    }
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
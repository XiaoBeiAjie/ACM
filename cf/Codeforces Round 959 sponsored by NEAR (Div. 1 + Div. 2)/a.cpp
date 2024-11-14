#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector w(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            cin >> w[i][j];
    if (n == 1 && m == 1) cout << "-1" << endl;
    else {
        for (int i = 1; i < n; i ++ ) {
            for (int j = 1; j < m; j ++ ) 
                cout << w[i + 1][j + 1] << " ";
            cout << w[i + 1][1] << endl;
        }
        for (int j = 1; j < m; j ++ ) 
            cout << w[1][j + 1] << " ";
        cout << w[1][1] << endl;
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
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector f(n + 1, vector<int> (22));
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i ++ ) 
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i ++ ) 
        cin >> f[i][0];
    for (int j = 1; j <= lg[n]; j ++ ) 
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) 
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        int k = lg[r - l + 1];
        cout << max(f[l][k], f[r - (1 << k) + 1][k]) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
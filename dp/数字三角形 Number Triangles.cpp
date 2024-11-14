#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long LL;

int n;
int f[N][N];
int w[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= i; j ++ ) 
            cin >> w[i][j];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= i; j ++ ) 
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + w[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, f[n][i]);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
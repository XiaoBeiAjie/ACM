#include <bits/stdc++.h>
using namespace std;
const int N = 360, M = 50;
typedef long long LL;

int n, m, x;
int f[M][M][M][M];
int cnt[4];
int w[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i <= m; i ++ ) 
        cin >> x, cnt[-- x] ++;
    f[0][0][0][0] = w[1];
    int ans = 0;
    for (int i = 0; i <= cnt[0]; i ++ ) 
        for (int j = 0; j <= cnt[1]; j ++ ) 
            for (int k = 0; k <= cnt[2]; k ++ ) 
                for (int t = 0; t <= cnt[3]; t ++ ) {
                    if (i) f[i][j][k][t] = max(f[i][j][k][t], f[i - 1][j][k][t] + w[i + 2 * j + 3 * k + 4 * t + 1]);
                    if (j) f[i][j][k][t] = max(f[i][j][k][t], f[i][j - 1][k][t] + w[i + 2 * j + 3 * k + 4 * t + 1]);
                    if (k) f[i][j][k][t] = max(f[i][j][k][t], f[i][j][k - 1][t] + w[i + 2 * j + 3 * k + 4 * t + 1]);
                    if (t) f[i][j][k][t] = max(f[i][j][k][t], f[i][j][k][t - 1] + w[i + 2 * j + 3 * k + 4 * t + 1]);
                    //cout << i << " " << j << " " << k << " " << t << " " << f[i][j][k][t] << endl;
                }
    cout << f[cnt[0]][cnt[1]][cnt[2]][cnt[3]] << endl;
                    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
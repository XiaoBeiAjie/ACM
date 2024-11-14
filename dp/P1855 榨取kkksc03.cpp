#include <bits/stdc++.h>
using namespace std;
const int N = 210;
typedef long long LL;

int n, m, v;
int t[N], c[N];
int f[N][N];

void solve() {
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i ++ ) 
        cin >> t[i] >> c[i];
    for (int i = 1; i <= n; i ++ ) 
         for (int j = m; j >= t[i]; j -- )
            for (int k = v; k >= c[i]; k -- ) 
                f[j][k] = max(f[j - t[i]][k - c[i]] + 1, f[j][k]);
    cout << f[m][v] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
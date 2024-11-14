#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long LL;

double f[N][N][2];

void solve() {
    int n, m;
    cin >> n >> m;
    f[0][0][0] = 1;
    for (int i = 0; i <= n; i ++ ) 
        for (int j = 0; j <= m; j ++ ) {
                int nn = n - i, mm = m - j;
                if (mm == 0) continue;
                int ll = nn + mm;
                double res = (double) mm / ll;
                f[i][j + 1][1] += f[i][j][0] * res;
                mm --, ll --;
                if (mm) f[i][j + 2][0] += f[i][j][1] * res * mm / ll;
                if (nn) f[i + 1][j + 1][0] += f[i][j][1] * res * nn / ll;
            }
    double ans = 0;
    for (int i = 0; i <= n; i ++ ) 
        for (int j = 0; j <= m; j ++ ) 
            if (f[i][j][0])
                ans += ((double) (n - i) / (n + m - i - j)) * f[i][j][0];
    cout << fixed << setprecision(9) << ans << endl; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
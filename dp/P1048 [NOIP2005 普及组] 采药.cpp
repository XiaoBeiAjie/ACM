#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 10000010;
typedef long long LL;

int n, m;
int v[N], w[N];
LL f[M];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++ ) 
        for (int j = w[i]; j <= m; j ++ )  
            f[j] = max(f[j - w[i]] + v[i], f[j]);
    cout << f[m] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
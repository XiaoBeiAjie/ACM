#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
typedef long long LL;

int n, m;
LL v[N], w[N], c[N];
LL f[N];

void solve() {
    int a, b;
    char ch;
    cin >> a >> ch >> b;
    m -= a * 60 + b;
    cin >> a >> ch >> b;
    m += a * 60 + b;
    cin >> n;
    
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i] >> v[i] >> c[i];
    for (int i = 1; i <= n; i ++ ) {    
        if (!c[i]) 
            for (int j = w[i]; j <= m; j ++ ) 
                f[j] = max(f[j - w[i]] + v[i], f[j]);
        else 
            for (int j = m; j >= w[i]; j -- ) 
                for (int k = 0; k * w[i] <= j && k <= c[i]; k ++ ) 
                    f[j] = max(f[j - k * w[i]] + k * v[i], f[j]);
    }
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
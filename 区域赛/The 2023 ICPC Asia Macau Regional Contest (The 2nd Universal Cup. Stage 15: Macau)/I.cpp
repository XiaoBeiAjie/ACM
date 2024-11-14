#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> f(m + 10);
    f[0] = 320;
    int t = (b + a - 1) / a * a;
    int ans = 320;
    for (int i = 1; i <= m; i ++ ) {
        if (i >= b) f[i] = max(f[i], f[i - b] + (b / a + 1) * 160);
        if (i >= t) f[i] = max(f[i], f[i - t] + ((b + a - 1) / a + 1) * 160);
    }
    for (int i = max(0, m - b); i <= m; i ++ ) 
        ans = max(ans, f[i] + (m - i) / a * 160);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
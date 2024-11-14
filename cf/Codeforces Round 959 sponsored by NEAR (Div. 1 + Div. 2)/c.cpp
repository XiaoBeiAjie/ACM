#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    LL n, x; cin >> n >> x;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i]; 
    vector<LL> w(n + 10);
    for (int i = 1; i <= n; i ++ ) 
        w[i] = w[i - 1] + a[i];
    vector<int> siz(n + 10);
    for (int i = 1, j = 1; i <= n; i ++ ) {
        while (j <= n && w[j] - w[i - 1] <= x) j ++;
        siz[j] += siz[i - 1] + 1;
    }
    LL ans = n * (n + 1) / 2;
    for (int i = 1; i <= n; i ++ ) 
        ans -= siz[i];
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
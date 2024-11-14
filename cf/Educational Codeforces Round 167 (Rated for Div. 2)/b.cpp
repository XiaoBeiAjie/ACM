#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef long long LL;

string a, b;
int f[N][N];
void solve() {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i ++ ) {
        int idx = i;
        for (int j = 1; j <= n; j ++ ) 
            if (idx <= m && b[idx] == a[j]) idx ++;
        ans = min(ans, i - 1 + m - idx + 1);
    }
    cout << ans + n << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
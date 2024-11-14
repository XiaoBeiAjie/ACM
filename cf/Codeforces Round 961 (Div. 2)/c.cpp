#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
const long double eps = 1e-12;

void solve() {
    int n; cin >> n;
    vector<long double> w (n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    int bg = n + 1;
    for (int i = 1; i <= n; i ++ ) {
        if (w[i] != 1) {
            bg = i;
            break;
        }
    }
    for (int i = bg; i <= n; i ++ ) {
        if (w[i] == 1) {
            cout << "-1" << endl;
            return ;
        }
    }
    long double cnt = 0;
    ll ans = 0;
    for (int i = bg; i <= n; i ++ ) 
        w[i] = log2(log2(w[i]));
    for (int i = bg + 1; i <= n; i ++ ) {
        long double res = w[i - 1] - w[i];
        if (res > eps) {
            int cnt = 1 + (res - eps) / log2(2);
            ans += cnt;
            w[i] += cnt * log2(2);
        };
    }
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
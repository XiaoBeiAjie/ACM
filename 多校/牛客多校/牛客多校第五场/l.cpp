#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    int sum = 0;
    ll ans = 1;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], sum += w[i];
    int l = 1, r = n; 
    while (l < r) {
        int len = r - l + 1;
        int avgl = sum / len, avgr = sum / len;
        if (sum % len) avgl ++;
        if (w[l] >= avgl) {
            sum -= w[l];
            l ++;
            continue;
        }
        if (w[r] <= avgr) {
            sum -= w[r];
            r --;
            continue;
        }
        if (w[l] < avgl) 
            w[l + 1] -= avgl - w[l], w[l] = avgl;
        if (w[r] > avgr) 
            w[r - 1] += w[r] - avgr, w[r] = avgr;
        sum -= w[l] + w[r];
        l ++, r --;
    }
    for (int i = 1; i <= n; i ++ ) 
        cerr << w[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++ ) 
        ans = ans * w[i] % mod;
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
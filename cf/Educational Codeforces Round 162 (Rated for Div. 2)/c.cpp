#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> w(n + 1), c(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        if (w[i] == 1) c[i] = 1;
        w[i] += w[i - 1];
        c[i] += c[i - 1];
    }
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        if (l == r) cout << "No\n";
        else if (w[r] - w[l - 1] < (r - l + 1 + c[r] - c[l - 1])) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
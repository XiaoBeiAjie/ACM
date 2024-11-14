#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin(), w.end());
    ll st = w[n], ed = w[n] + k;
    for (int i = 1; i < n; i ++ ) {
        ll l, r;
        ll res = (w[n] - w[i]) / k;
        if (!(res & 1)) l = w[n], r = w[i] + k * res + k;
        else l = w[i] + k * res + k, r= w[n] + k;
        //cerr << l << "!!!" << r << "\n";
        if (r <= st || l >= ed) return cout << "-1\n", void();
        st = max(st, l);
        ed = min(ed, r);
    }
    if (ed == st) return cout << "-1\n", void();
    cout << st << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
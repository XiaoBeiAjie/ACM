#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> x(n + 1), w(n + 1);
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int i = 1; i <= n; i ++ ) {
        int t; cin >> t;
        if (t < 0) t = -t;
        x[t] = 1, w[t] += a[i];
    }
    ll res = 0;
    for (int i = 1; i <= n; i ++ ) 
        w[i] += w[i - 1];
    for (int i = 1; i <= n; i ++ ) 
        if (w[i] > i * k) 
            return cout << "No\n", void();
    
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    int t = w[1];
    for (int i = 2; i <= n; i ++ ) 
        t = __gcd(t, w[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (w[i] == t) cnt ++;
    if (cnt > 1) return cout << "No\n", void();
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
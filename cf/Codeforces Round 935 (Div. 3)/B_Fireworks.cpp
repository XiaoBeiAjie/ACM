#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << (m / a + 1 + m / b + 1) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
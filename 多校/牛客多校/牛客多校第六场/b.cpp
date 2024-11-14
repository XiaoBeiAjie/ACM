#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    if (n == 2 * k) return cout << n << "\n", void();
    k = min(k, n - k);
    cout << k * n + 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
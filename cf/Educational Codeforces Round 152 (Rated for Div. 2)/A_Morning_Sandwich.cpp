#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int t = min(a - 1, b + c);
    cout << 2 * t + 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
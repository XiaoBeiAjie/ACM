#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b % 3 && b % 3 + c < 3) cout << "-1\n";
    else cout << a + (b + c + 2) / 3 << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
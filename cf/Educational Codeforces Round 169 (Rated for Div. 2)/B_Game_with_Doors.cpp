#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int l = max(l1, l2), r = min(r1, r2);
    if (l > r) cout << "1\n";
    else cout << r - l + (max(r1, r2) > r) + (min(l1, l2) < l) << "\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
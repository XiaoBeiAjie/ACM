#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (x + k >= y) 
        cout << max(y, x) << "\n";
    else 
        cout << y + (y - x - k) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
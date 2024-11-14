#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int x, n;

void solve() {
    cin >> x >> n;
    set<int> s;
    for (int i = 1; i <= x / i; i ++ ) 
        if (x % i == 0) s.insert(i), s.insert(x / i);
    int ans = 0;
    for (auto u : s) 
        if (u <= x / n) ans = max(ans, u);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> f(n + 1);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i ++ ) 
        f[i] = f[i - 1]  + f[i - 2];
    cout << f[n] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
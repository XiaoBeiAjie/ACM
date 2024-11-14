#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<int> g(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> g[i], ans = max(ans, g[i]);
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
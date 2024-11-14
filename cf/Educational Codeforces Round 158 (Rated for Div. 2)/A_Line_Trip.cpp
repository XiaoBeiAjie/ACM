#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    for (int i = 1; i <= n; i ++ ) 
        ans = max(ans, w[i] - w[i - 1]);
    ans = max(ans, 2 * (x - w[n]));
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
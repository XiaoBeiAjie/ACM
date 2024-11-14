#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ )  
        cin >> w[i];
    ll ans = 0;
    ans += w[1] - 1;
    for (int i = 2; i <= n; i ++ ) 
        if (w[i] > w[i - 1]) 
            ans += w[i] - w[i - 1];
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
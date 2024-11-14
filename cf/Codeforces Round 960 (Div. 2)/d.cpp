#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    int ans = 0;
    vector<int> f(n + 1);
    for (int i = 1; i < n; i ++ ) {
        if (!w[i]) continue;
        if (f[i] && w[i + 1] <= 4) 
            ans ++, w[i + 1] = min(w[i + 1], 2);
        else if (w[i] <= 2) 
            if (w[i + 1] <= 2) w[i + 1] = 0, ans ++;
            else if (w[i + 1] <= 4) f[i + 1] = 1, ans ++;
            else ans ++;  
        else ans ++;
    }
    if (w[n]) ans ++;
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
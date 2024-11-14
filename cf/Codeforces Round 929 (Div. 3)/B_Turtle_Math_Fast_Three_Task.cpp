#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    ll sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        sum += w[i];
    if (sum % 3 == 0) return cout << "0\n", void();
    if (sum % 3 == 1) {
        for (int i = 1; i <= n; i ++ )  
            if (w[i] % 3 == 1) return cout << "1\n", void();
        return cout << "2\n", void();
    }
    if (sum % 3 == 2) return cout << "1\n", void();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
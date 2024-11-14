#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "Yes\n" << n << "\n";
        for (int i = 1; i <= n; i ++ ) 
            cout << 1 << " \n"[i == n];
        return ;
    }
    if (k == 1) return cout << "No\n", void();
    if (!(n & 1)) {
        cout << "Yes\n";
        cout << (n >> 1) << "\n";
        for (int i = 1; i <= n >> 1; i ++ ) 
            cout << 2 << " \n"[i == n >> 1];
        return ;
    }
    if (k == 2) return cout << "No\n", void();
    cout << "Yes\n";
    cout << (((n - 3) >> 1 )+ 1) << "\n";
    cout << 3 << " ";
    for (int i = 1; i <= (n - 3) >> 1; i ++ ) 
        cout << 2 << " \n"[i == ((n - 3) >> 1)];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
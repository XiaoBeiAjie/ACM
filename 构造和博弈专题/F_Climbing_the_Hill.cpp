#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    while (cin >> n >> k) {
        int ans = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        a[0] = 0;
        if (k == 1) {
            cout << "Alice\n";
            continue;
        }
        else if (k != 2) a[0] = -1;
        for (int i = n; i >= 1; i -= 2) ans ^= a[i] - a[i - 1] - 1;
        cout << (ans ? "Alice\n" : "Bob\n"); 
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
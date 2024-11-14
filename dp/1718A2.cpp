#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) 
        a[i] ^= a[i - 1];
    map<int, int> mp;
    vector<int> f(n + 1);
    mp[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        f[i] = f[i - 1];
        if (mp.find(a[i]) != mp.end()) 
            f[i] = max(f[i], f[mp[a[i]]] + 1);
        mp[a[i]] = i;
    }
    cout << n - f[n] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
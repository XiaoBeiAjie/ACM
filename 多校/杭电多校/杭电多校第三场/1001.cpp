#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = i; j <= n; j += i) 
            f[j] = (f[j] + f[i - 1]) % mod;
    for (int i = 1; i <= n; i ++ ) 
        cout << f[i] << " ";
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
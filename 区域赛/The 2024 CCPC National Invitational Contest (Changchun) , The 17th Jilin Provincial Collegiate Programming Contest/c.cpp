#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010, mod = 1000000007;
typedef long long LL;

int T, n;
string s;

void solve() {
    cin >> s;
    n = s.size();
    s = " " + s;
    vector<int> F(2 * n + 10);
    F[1] = 1, F[2] = 1;
    for (int i = 3; i <= 2 * n; i ++ ) 
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    LL ans = 0, cnt = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (s[i] == '1') ans = (ans + F[2 * (n - i) + cnt]) % mod, cnt ++;
    cout << (ans + F[cnt]) % mod << endl;
}

int main(void) {
    T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
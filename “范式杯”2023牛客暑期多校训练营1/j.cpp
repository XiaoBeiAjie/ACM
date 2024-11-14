#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long LL;


LL n, m;
LL qmi(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    m += n;
    LL t = qmi(2, mod - 2);
    LL bt;
    for (bt = 60; bt; bt -- ) 
        if ((n >> bt) & 1) 
            break;#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long LL;


LL n, m;
LL qmi(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    m += n;
    LL t = qmi(2, mod - 2);
    LL bt;
    for (bt = 60; bt; bt -- ) 
        if ((n >> bt) & 1) 
            break;
    LL ans = 1;
    if (n == (1LL << (bt + 1)) - 1) bt ++;
    while (n < m) {
        LL t_ = min(m - n, (1LL << (bt + 1)) - n - 1);
        LL res = (1 - qmi(t, bt) + mod) % mod;
        ans = ans * qmi(res, t_) % mod;
        n += t_;
        bt ++;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
        bt ++;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
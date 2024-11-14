#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 60, mod = 998244353;
typedef long long LL;

vector<int> fac[N];
int f[N][2];
class LBase {
public :
    int p[M], d[M], pcnt{}, dcnt{};
    bool zero = false;
    LBase() {
        memset(p, 0, sizeof p);
    }
    bool insert(int x) {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                if (p[i] == 0) {
                    p[i] = x;
                    pcnt ++;
                    return true;
                } else {
                    x ^= p[i];
                }
            }
        }
        zero = true;
        return false;
    }
    int qmin() {
        if (zero) return 0;
        for (int i = 0; i <= 60; i++) {
            if (p[i]) return p[i];
        }
    }
    int qmx() {
        int ans = 0;
        for (int i = 60; i >= 0; i--) {
            if ((ans ^ p[i]) > ans) ans ^= p[i];
        }
        return ans;
    }
    void rebuild() {
        dcnt = 0;
        for (int i = 0; i <= 60; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (p[i] >> j & 1) {
                    p[i] ^= p[j];
                }
            }
            if (p[i]) {
                d[dcnt ++] = p[i];
            }
        }
    }
    //这里可能需要rebuild
    int kth(int k) {
        if (zero) k --;
        int ans = 0;
        for (int i = 0; i < dcnt; i++) {
            if (k >> i & 1) {
                ans ^= d[i];
            }
        }        
        return ans;
    }
};

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> w(n), cnt(n + 1);
    for (auto &u : w)
        cin >> u, cnt[u] ++;
    LBase base;
    for (auto u : w) 
        base.insert(u);
    int ans = (qmi(2, n - base.pcnt) - 1 + mod) % mod; 
    for (int i = 1; i <= n; i ++ ) {
        if (!cnt[i]) continue;
        LBase b;
        int size_ = 0;
        for (auto u : fac[i]) {
            if (cnt[u]) 
                b.insert(u);
                size_ += cnt[u];
        }
        ans = (ans + 1LL * qmi(2, size_ - b.pcnt) * f[cnt[i]][1] % mod) % mod;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for (int i = 1; i <= 200000; i ++ ) 
        for (int j = 2 * i; j <= 200000; j += i ) 
            fac[j].push_back(i);
    f[1][1] = 1;
    for (int i = 2; i <= 100000; i ++ ) {
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
        f[i][1] = (1 + f[i - 1][0] + f[i - 1][1]) % mod;
    }
        
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
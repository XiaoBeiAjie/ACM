#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 998244353;
typedef long long ll;

int primes[N], idx;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[idx ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    get_primes(1010);
    int n;
    cin >> n;
    vector<ll> f(n + 1), cnt(n + 1), g(n + 1);  
    f[1] = 1;   
    for (int i = 2; i <= n; i ++ ) {
        int x = i, ans = 1;
        for (int j = 0; j < idx; j ++ ) 
            if (x % primes[j] == 0) {
                int res = 0;
                while (x % primes[j] == 0) res ++, x /= primes[j];
                ans = 1ll * (res + 1) * ans % mod; 
            }
            else if (x < primes[j]) break;
        if (x != 1) ans = 2 * ans % mod;
        cnt[i] = (ans - 1 + mod) % mod;
        f[i] = (f[i - 1] + cnt[i]) % mod;
    }      
        
    for (int i = 1; i <= n; i ++ ) 
        cout << f[i] << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
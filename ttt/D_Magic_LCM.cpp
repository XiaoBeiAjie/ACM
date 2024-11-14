#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1010;

int primes[N], cnt;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) 
                break;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    constexpr int mod = 998244353;
    function<i64(i64, i64)> qmi = [&] (i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) {
        int x = w[i];
        for (int j = 0; j < cnt && x >= primes[j]; j ++ ) {
            if (x % primes[j] == 0) {
                int c = 0;
                while (x % primes[j] == 0) 
                    x /= primes[j], c ++;
                mp[primes[j]].push_back(c);
            }
        }
        if (x != 1) mp[x].push_back(1);
    }
    vector<i64> ans(n, 1);
    for (auto [u, v] : mp) {
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < v.size(); i ++ ) 
            ans[i] = ans[i] * qmi(u, v[i]) % mod;
    }
    i64 sum = 0;
    for (int i = 0; i < n; i ++ ) 
        sum = (sum + ans[i]) % mod;
    cout << sum << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    get_primes(1000);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
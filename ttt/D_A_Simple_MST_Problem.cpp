#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;

int primes[N], w[N], cnt;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int l, r; cin >> l >> r;
    if (l == 1) {
        i64 ans = 0;
        for (int i = l; i <= r; i ++ ) 
            ans += w[i];
        cout << ans << "\n";
        return ;
    }
    i64 re = 0;
    vector<int> st(r + 1);
    vector<int> v;
    for (int i = l; i <= r; i ++ ) {
        if (st[i]) continue;
        v.push_back(i);
        for (int j = i + i; j <= r; j += i) 
            if (!st[j]) {
                re += w[j];
                st[j] = 1;
            }
    } 
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    get_primes(1000);
    for (int i = 2; i <= 1000000; i ++ ) {
        int x = i;
        for (int j = 0; j < cnt && x >= primes[j]; j ++ ) {
            if (x % primes[j] == 0) {
                while (x % primes[j] == 0) 
                    x /= primes[j];
                w[i] ++;
            }
        }
        if (x != 1) w[i] ++;
    }
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
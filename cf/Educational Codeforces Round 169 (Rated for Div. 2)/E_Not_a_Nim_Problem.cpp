#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes, sg(10000001);
vector<bool> st(10000001);

void fun() {
    int n = 10000000;
    sg[1] = 1, sg[2] = 0;
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes.push_back(i);
            if (i != 2) sg[i] = primes.size();
        }
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            sg[primes[j] * i] = sg[primes[j]];
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], w[i] = sg[w[i]];
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        sum ^= w[i];
    cout << (sum ? "Alice\n" : "Bob\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fun();
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
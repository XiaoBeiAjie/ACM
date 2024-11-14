#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve() {
    mt19937 rng(23332);
    uniform_int_distribution<int> rnd(1, 1000000000);
    constexpr int base = 3333;
    i64 n = 0;
    vector<i64> sum(10001);
    int maxx = 0;
    map<int, int> mp;
    int time = 1;
    while (time <= base) {
        int x = rnd(rng);
        cout << "walk " << x << endl;
        int u; cin >> u;
        maxx = max(u, maxx);
        sum[time] = sum[time - 1] + x;
        if (mp.find(u) != mp.end()) 
            n = gcd(n, sum[time] - sum[mp[u]]);
        mp[u] = time;
        time ++;
    }
    while (time <= 2 * base) {
        cout << "walk " << 1 << endl;
        int u; cin >> u;
        maxx = max(u, maxx);
        sum[time] = sum[time - 1] + 1;
        if (mp.find(u) != mp.end()) 
            n = gcd(n, sum[time] - sum[mp[u]]);
        mp[u] = time;
        time ++;
    }
    {
        cout << "walk " << maxx << endl;
        int u; cin >> u;
        maxx = max(u, maxx);
        sum[time] = sum[time - 1] + maxx;
        if (mp.find(u) != mp.end()) 
            n = gcd(n, sum[time] - sum[mp[u]]);
        mp[u] = time;
        time ++;
    }
    while (time <= 10000) {
        cout << "walk " << base << endl;
        int u; cin >> u;
        maxx = max(u, maxx);
        sum[time] = sum[time - 1] + base;
        if (mp.find(u) != mp.end()) 
            n = gcd(n, sum[time] - sum[mp[u]]);
        mp[u] = time;
        time ++;
    }
    cout << "guess " << max(n, maxx) << endl;
}

signed main(void) {
    int T = 1;
    while (T -- ) solve();
    return 0;
}
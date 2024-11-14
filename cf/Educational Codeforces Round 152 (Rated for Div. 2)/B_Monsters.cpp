#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], w[i] %= k, mp[w[i]].push_back(i);
    for (auto u : mp[0]) 
        cout << u << " ";
    for (auto t = mp.rbegin(); t != mp.rend(); t ++) {
        if (t -> first == 0) continue;
        auto v = t -> second;
        for (auto u : v) 
            cout << u << " ";
    } 
    cout << "\n";

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    vector<array<int, 3>> w(k + 1);
    for (int i = 1; i <= k; i ++ ) 
        cin >> w[i][0] >> w[i][1] >> w[i][2];
    vector<int> b(k + 1);
    iota(b.begin(), b.end(), 0);
    sort(b.begin() + 1, b.end(), [&] (int &i, int &j) {
        return w[i][2] < w[j][2];
    });
    int lst = 0;
    if (w[b[1]][2] - lst > 2) return cout << "NO\n", void();
    if (m + 1 - w[b[k]][2] > 2) return cout << "NO\n", void();
    for (int i = 1; i < k; i ++ ) 
        if (w[b[i + 1]][2] - w[b[i]][2] > 2) 
            return cout << "NO\n", void();
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n), b(n);
    iota(b.begin(), b.end(), 0);
    for (int i = 0; i < n; i ++ ) 
        cin >> w[i];
    sort(b.begin(), b.end(), [&] (int &i, int &j) { 
        return w[i] < w[j];
    });
    vector<int> ans(n);
    for (int i = 0; i < n; i ++ ) 
        ans[b[i]] = w[b[(i + 1) % n]];
    for (int i = 0; i < n; i ++ ) 
        cout << ans[i] << " \n"[i == n - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> a;
    for (int i = 1; i <= n; i ++ ) {
        if (!w[i]) a.push_back(0);
        else {
            int t = 1, j = i;
            while (j <= n && w[j]) t = max(t, w[j ++]);
            i = j - 1;
            a.push_back(t); 
        }
    }
    int n_ = a.size();
    vector<int> f(n_);
    for (int i = 0; i < n_; i ++ ) {
        if (!a[i]) continue;
        if (a[i] == 1) {
            if (i && !f[i - 1]) f[i - 1] = 1;
            else if (i != n_ - 1) f[i + 1] = 1;
        }
        else if (a[i] == 2) {
            if (i && !f[i - 1]) f[i - 1] = 1;
            if (i != n_ - 1) f[i + 1] = 1;
        }
    }
    cout << count(f.begin(), f.end(), 0) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin() + 1, w.end());
    if (n == 1) {
        cout << "1\n" << w[1] << "\n";
        return ;
    }
    for (int i = 1; i < n; i ++ ) 
        if ((w[i + 1] - w[i]) & 1) {
            cout << "-1\n";
            return ;
        }
    vector<int> ans;
    while (true) {
        int idx = 0;
        for (int i = 1; i <= n; i ++ ) 
            idx = max(idx, w[i]);
        if (!idx) break;
        int t = max(w[n] >> 1, 1);
        for (int i = 1; i <= n; i ++ ) 
            w[i] = abs(w[i] - t);
        ans.push_back(t);
    }
    
    cout << ans.size() << "\n";
    for (auto u : ans) 
        cout << u << " ";
    cout << "\n";
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
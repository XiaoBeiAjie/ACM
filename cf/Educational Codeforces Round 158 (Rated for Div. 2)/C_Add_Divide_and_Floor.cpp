#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i ++ ) 
        cin >> w[i];
    sort(w.begin(), w.end());
    if (w[0] == w[n - 1]) 
        return cout << "0\n", void();
    vector<int> ans;
    while (w[0] != w[n - 1]) {
        if (!(w[n - 1] & 1)) {
            ans.push_back(1);
            w[0] ++, w[n - 1] ++;
        }
        else 
            ans.push_back(0);
        w[0] >>= 1, w[n - 1] >>= 1;
    }
    cout << ans.size() << "\n";
    if (ans.size() <= n) 
        for (int i = 0; i < ans.size(); i ++ ) 
            cout << ans[i] << " \n"[i == ans.size() - 1];
     
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
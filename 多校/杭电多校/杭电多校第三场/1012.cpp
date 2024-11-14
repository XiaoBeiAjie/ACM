#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, l, d;
    cin >> n >> l >> d;
    vector<int> w(n + 1);
    int res = 0;
    cin >> res;
    for (int i = 2; i <= n; i ++ ) 
        cin >> w[i];
    sort(w.begin() + 2, w.end());
    vector<int> ans(5);
    if (res >= l) 
        ans[1] = w[2], ans[2] = w[3], ans[3] = w[4], ans[4] = res;
    else 
        ans[1] = w[2], ans[2] = w[3], ans[3] = res, ans[4] = w[n];
    sort(ans.begin(), ans.end());
    if (ans[4] >= l && ans[3] >= l) return cout << "No\n", void();
    else if (ans[4] - ans[1] <= d) return cout << "No\n", void();
    else cout << "Yes\n", void();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
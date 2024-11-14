#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        pre[i] = pre[i - 1] + w[i];
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for (int r = 1; r <= n; r ++ ) {
        int res = pre[r] - k;
        // 如果没找到 不能新建副本cnt[res]如果没有 直接访问从cnt[res] 会新建cnt[res] = 0;
        if (cnt.find(res) != cnt.end()) ans += cnt[res];
        cnt[pre[r]] ++;
    }  
    cout << ans << "\n";
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    while (T -- ) solve();
    return 0;
}
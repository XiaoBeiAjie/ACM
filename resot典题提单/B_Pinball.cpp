#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> pos_l, pos_r;
    pos_l.push_back(0), pos_r.push_back(0);
    for (int i = 1; i <= n; i ++ ) 
        if (s[i] == '<') 
            pos_l.push_back(i);
        else 
            pos_r.push_back(i);
    int cnt_l = pos_l.size() - 1, cnt_r = pos_r.size() - 1;
    vector<i64> pre_l(cnt_l + 1), pre_r(cnt_r + 1);
    for (int i = 1; i <= cnt_l; i ++ ) 
        pre_l[i] = pre_l[i - 1] + pos_l[i];
    for (int i = 1; i <= cnt_r; i ++ ) 
        pre_r[i] = pre_r[i - 1] + pos_r[i];
    for (int i = 1; i <= n; i ++ ) {
        i64 ans = 0;
        auto idx_l = lower_bound(pos_l.begin(), pos_l.end(), i) - pos_l.begin();
        auto idx_r = lower_bound(pos_r.begin(), pos_r.end(), i) - pos_r.begin();
        if (s[i] == '<') {
            idx_r --;
            if (cnt_l - idx_l + 1 > idx_r) 
                ans = 2 * (pre_l[idx_l + idx_r] - pre_l[idx_l - 1]) - i - 2 * pre_r[idx_r];
            else {
                int t = cnt_l - idx_l + 1;
                ans = 2 * (pre_l[cnt_l] - pre_l[idx_l - 1]) - i - 2 * (pre_r[idx_r] - pre_r[idx_r - t]) + n + 1;
            }
        }
        else {
            if (cnt_l - idx_l + 1 >= idx_r) 
                ans = 2 * (pre_l[idx_l + idx_r - 1] - pre_l[idx_l - 1]) + i - 2 * pre_r[idx_r]; 
            else {
                int t = cnt_l - idx_l + 1;
                ans = 2 * (pre_l[cnt_l] - pre_l[idx_l - 1]) + i - 2 * (pre_r[idx_r] - pre_r[idx_r - t - 1]) + n + 1;
            }
        }
        cout << ans << " \n"[i == n];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
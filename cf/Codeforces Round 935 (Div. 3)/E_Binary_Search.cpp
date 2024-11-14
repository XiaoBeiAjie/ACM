#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> w(n + 1);
    int idx, id1, idn;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        if (w[i] == x) 
            idx = i;
        if (w[i] == 1) 
            id1 = i;
        if (w[i] == n) 
            idn = i;
    }
    if (x == 1) {
        if (idx == 1) 
            return cout << "0\n", void();
        else {
            cout << "1\n";
            cout << idx << " " << 1 << "\n";
            return ;
        }
    }
    if (x == n) {
        if (idx == n) 
            return cout << "0\n", void();
        else {
            cout << "1\n";
            cout << idx << " " << n << "\n";
            return ;
        }   
    }
    vector<pair<int, int>> ans;
    if (w[n + 2 >> 1] <= x && idx >= (n + 2 >> 1)) {
        ans.push_back({idn, n + 2 >> 1});
        if (n + 2 >> 1 == idx) idx = idn;
        swap(w[idn], w[n + 2 >> 1]);
    }
    else if (w[n + 1 >> 1] > x && idx < (n + 2 >> 1)) {
        ans.push_back({id1, n + 2 >> 1});
        if (n + 2 >> 1 == idx) idx = id1;
        swap(w[id1], w[n + 2 >> 1]);
    }
    int l = 1, r = n + 1; 
    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (w[mid] <= x) l = mid;
        else r = mid;
    }
    if (idx != l) {
        ans.push_back({idx, l});
        //swap(w[idx], w[l]);
    }
    // l = 1, r = n + 1; 
    // while (l + 1 != r) {
    //     int mid = l + r >> 1;
    //     if (w[mid] <= x) l = mid;
    //     else r = mid;
    // }
    // cerr << w[l] << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++ ) 
        cout << ans[i].first << " " << ans[i].second << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
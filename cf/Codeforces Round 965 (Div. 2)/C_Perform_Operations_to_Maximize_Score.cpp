#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

struct Node {
    ll val, tag;
    bool operator < (const Node &rhs) const {
        if (val == rhs.val) 
            return tag < rhs.tag;
        return val < rhs.val;
    }
};

void solve() {
    ll n, k; cin >> n >> k;
    vector<Node> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i].val;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i].tag;
    sort(w.begin(), w.end());
    int idx = n;
    ll ans = 0;
    while (idx && !w[idx].tag) idx --;
    if (idx && w[idx].val + k > w[n].val) {
        int mid = n >> 1;
        if (idx <= mid) mid ++ ;
        ans = w[idx].val + k + w[mid].val;
    }
    n --;
    int len = n >> 1;
    len ++;
    function<bool(ll)> check = [&] (ll mid) {
        int cnt = 0, res = k;
        for (int i = n; i; i -- ) 
            if (w[i].val >= mid) cnt ++;
            else if (w[i].tag && mid - w[i].val <= res) res -= mid - w[i].val, cnt ++;
        return cnt >= len;
    };
    ll l = 1, r = 2e9;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << max(l + w[n + 1].val, ans) << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
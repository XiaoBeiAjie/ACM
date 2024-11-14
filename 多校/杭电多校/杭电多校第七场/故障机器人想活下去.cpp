#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    function<bool(int)> check = [&] (int mid) {
        ll sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= mid; i ++ ) {
            if (q.size() < k) q.push(w[i]);
            else if (!q.empty() && q.top() < w[i]) {
                sum += q.top();
                q.pop();
                q.push(w[i]);
            }
            else sum += w[i];
            if (sum >= x) return false;
        }
        return true;
    };
    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
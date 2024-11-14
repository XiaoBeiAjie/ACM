#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i], c[i] = a[i];
    for (int i = 1; i <= n; i ++ )
        cin >> b[i], d[i] = b[i];
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 1; i <= n; i ++ ) 
        if (c[i] != d[i]) {
            cout << "No\n";
            return ;
        }
    vector<int> tmp(n + 1);
    function<int(vector<int>&, int, int)> merge_sort = [&] (vector<int>& q, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = 0;
        res += merge_sort(q, l, mid); res += merge_sort(q, mid + 1, r);
        int i = l, j = mid + 1, idx = 0;
        while (i <= mid && j <= r) {
            if (q[i] <= q[j]) tmp[++ idx] = q[i ++];
            else tmp[++ idx] = q[j ++], res += (mid - i + 1);
        }
        while (i <= mid) 
            tmp[++ idx] = q[i ++];
        while (j <= r) 
            tmp[++ idx] = q[j ++];
        for (int i = 1; i <= idx; i ++ ) 
            q[i + l - 1] = tmp[i];
        return res; 
    };
    int cnt1 = merge_sort(a, 1, n), cnt2 = merge_sort(b, 1, n);
    //cerr << cnt1 << " " << cnt2 << "\n";
    if ((cnt1 - cnt2) & 1) cout << "No\n";
    else cout << "Yes\n";
} 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
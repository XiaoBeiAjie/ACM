#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> x(n), y(n), r(n), l(n);
    for (auto &it : x) cin >> it;
    for (auto &it : y) cin >> it;
    sort(x.begin(), x.end());
    int j = n - 1;
    for (int i = n - 1; i >= 0; i -- ) {
        while (x[j] - x[i] > k) j --;
        r[i] = j - i + 1;
        if (i + 1 < n) r[i] = max(r[i], r[i + 1]);
    }
    j = 0;
    for (int i = 0; i < n; i ++ ) {
        while (x[i] - x[j] > k) j ++;
        l[i] = i - j + 1;
        if (i) l[i] = max(l[i], l[i - 1]);
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i ++ )
        ans = max(ans, l[i] + r[i + 1]);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
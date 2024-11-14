#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 200010;
typedef long long LL;

int T;
int L, R, n;
string s;

void solve() {
    cin >> n >> L >> R;
    cin >> s;
    vector<int> z(n + 10);
    int l = 0, r = 0;
    for (int i = 1; i < n; i ++ ) {
        if (i < r) 
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] ++;
        if (i + z[i] > r) 
            l = i, r = i + z[i];
    }
    auto check = [&](int x, int t) {
        int cnt = 1;
        for (int i = x; i < n; i ++ ) {
            if (z[i] >= x) cnt ++, i += x - 1;
            if (cnt >= t) return true;
        }
        return cnt >= t;
    };
    int last = n, nn = ceil(sqrt(n));
    vector<int> ans(n + 10);
    for (int i = L; i <= nn; i ++ ) {
        l = 0, r = last;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, i)) l = mid;
            else r = mid - 1;
        }
        last = ans[i] = l;
    }
    for (int len = 1; len <= nn; len ++ ) {
        int cnt = 1;
        for (int i = len; i < n; i ++ ) 
            if (z[i] >= len) cnt ++, i += len - 1;
        ans[cnt] = max(ans[cnt], len);
    }
    for (int i = n - 1; i >= L; i -- ) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = L; i <= R; i ++ ) std::cout << ans[i] << " ";
    std::cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);std::cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
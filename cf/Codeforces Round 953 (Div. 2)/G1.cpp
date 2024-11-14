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
    auto check = [&](int x) {
        int cnt = 1;
        for (int i = x; i < n; i ++ ) 
            if (z[i] >= x) cnt ++, i += x - 1;
        return cnt >= L;
    };
    l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
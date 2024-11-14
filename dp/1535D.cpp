#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int k, q;
string s;

void solve() {
    cin >> k >> s;
    reverse(s.begin(), s.end());
    s = " " + s;
    int n = 1 << k;
    vector<int> cnt(2 * n + 2, 1);

    auto update = [&](int i) {
        return cnt[i] = (s[i] != '0' ? cnt[i << 1] : 0) + (s[i] != '1' ? cnt[(i << 1) + 1] : 0);
    };
    
    for (int i = n - 1; i; i -- ) 
        update(i);
    cin >> q;
    while (q -- ) {
        int p;
        char c;
        cin >> p >> c;
        p = n - p;
        s[p] = c;
        while (p)
            update(p), p >>= 1;
        cout << cnt[1] << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
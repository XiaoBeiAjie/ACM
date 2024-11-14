#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

LL qmi(LL a, int b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s;
    int x;
    cin >> s >> x;
    reverse(s.begin(), s.end());
    LL ans = 0;
    for (int i = 0; i < s.size(); i ++ ) {
        s[i] -= '0';
        if (s[i] > x) s[i] --;
        //cout << qmi(9LL, i) << " " << i << endl;
        ans += 1LL * s[i] * qmi(9LL, i); 
    }
    cout << ans + 1 << endl; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
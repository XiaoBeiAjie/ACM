#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    map<int, int> mp; 
    bool f = false;
    int st = 0, last = 0x3f3f3f3f, be = 0x3f3f3f3f;
    for (int i = 1; i <= m; i ++ ) {
        int op; cin >> op;
        if (op == 1) {
            if (f) cout << "bad\n";
            else cout << st << "\n";
        }
        else if (op == 2) {
            if (f) cout << "bad\n";
            else if (last == 0x3f3f3f3f) cout << "inf\n";
            else cout << last << "\n";
        }
        else {
            int p, q;
            cin >> q >> p;
            if (f) continue; 
            if (mp.find(p) != mp.end() && mp[p] != q) 
                f = true;
            else if ((mp.empty() || mp.begin() -> first > p) && q - 1 > p) 
                f = true;
            else {
                if (q == 1 && p <= last) {
                    if (p < be) st = max(st, p);
                    continue;
                }
                if (mp.empty() || p < mp.begin() -> first) {
                    if (q != 1) be = min(be, p);
                    st = max(st, ((p - q + 1) & 1) ? 1 : 0);
                    last = min(last, p - q + 1);
                }
                    
                mp[p] = q; 
                auto it = mp.find(p);
                if (it != mp.begin()) {
                    it --;
                    int t1 = abs(q - it -> second), t2 = abs(p - it -> first);
                    if (t1 > t2 || ((t2 - t1) & 1))
                        f = true;
                    it ++;
                }
                it ++;
                if (it != mp.end()) {
                    it ++;
                    int t1 = abs(q - it -> second), t2 = abs(p - it -> first);
                    if (t1 > t2 || ((t2 - t1) & 1))
                        f = true;
                }

            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
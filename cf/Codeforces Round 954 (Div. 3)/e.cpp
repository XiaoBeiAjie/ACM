#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n, k;
int w[N];


void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) 
        mp[w[i] % k].push_back(w[i] / k);
    int cnt = 0;
    for (auto [x, y] : mp) 
        if ((int) y.size() & 1) {
            cnt ++;
            if (cnt > 1) return cout << "-1" << endl, void();
        }
    LL ans = 0;
    for (auto &[x, y] : mp) {
        sort(y.begin(), y.end());
        if (y.size() & 1) {
            if (y.size() == 1) continue;
            vector<LL> l(y.size()), r(y.size());
            l[1] = y[1] - y[0];
            for (int i = 3; i < y.size(); i += 2 ) 
                l[i] = l[i - 2] + y[i] - y[i - 1];
            r[y.size() - 2] = y[y.size() - 1] - y[y.size() - 2];
            for (int i = y.size() - 4; i >= 0; i -= 2)
                r[i] = r[i + 2] + y[i + 1] - y[i];
            LL res = 0x3f3f3f3f3f;
            for (int i = 2; i <= y.size() - 3; i += 2) 
                res = min(res, l[i - 1] + r[i + 1]); 
            ans += min({res, r[1], l[y.size() - 2]});

        }
        else {
            for (int i = 0; i < y.size() - 1; i += 2 ) 
                ans += y[i + 1] - y[i];
        }  
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
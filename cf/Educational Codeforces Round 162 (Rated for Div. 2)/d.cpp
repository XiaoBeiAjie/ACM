#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1);
    vector<ll> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], pre[i] = w[i] + pre[i - 1];
    suf[n] = w[n];
    for (int i = n - 1; i; i -- ) 
        suf[i] = w[i] + suf[i + 1];
    constexpr int inf = 0x3f3f3f3f;
    reverse(suf.begin() + 1, suf.end());
    vector<int> l(n + 1), r(n + 1);
    l[1] = -inf;
    for (int i = 2; i <= n; i ++ ) 
        if (w[i] != w[i - 1]) 
            l[i] = i - 1;
        else 
            l[i] = l[i - 1];
    r[n] = inf;
    for (int i = n - 1; i; i -- ) 
        if (w[i] != w[i + 1]) 
            r[i] = i + 1;
        else 
            r[i] = r[i + 1];
    for (int i = 1; i <= n; i ++ ) {
        if ((i != 1 && w[i - 1] > w[i]) || (i != n && w[i + 1] > w[i])) {
            cout << "1 ";
            continue;
        }
            
        int lans = inf, rans = inf;
        lans = (i == 1 ? inf : i - l[i - 1]);
        rans = (i == n ? inf : r[i + 1] - i);
        auto t = upper_bound(pre.begin(), pre.end(), pre[i] + w[i]);
        if (t == pre.end()) 
            rans = inf;
        else 
            rans = max(rans, (int) (t - pre.begin()) - i);   
        t = upper_bound(suf.begin(), suf.end(), suf[n + 1 - i] + w[i]);
        if (t == suf.end()) 
            lans = inf;
        else 
            lans = max(lans, i - (n + 1 - (int) (t - suf.begin())));
        int ans = min(lans, rans);
        //cerr << "<<" << lans << " " << rans << "\n";
        if (ans >= inf / 2) cout << "-1 ";
        else cout << ans << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
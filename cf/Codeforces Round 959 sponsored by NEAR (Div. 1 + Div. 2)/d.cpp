#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), fa(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], fa[i] = i;
    function<int(int)> find = [&] (int x) {
        return (fa[x] == x) ? x : find(fa[x]);
    };
    vector<pair<int, int>> ans(n);
    for (int i = n - 1; i; i -- ) {
        int s, t;
        vector<int> f(i);
        for (int v = 1; v <= n; v ++ ) {
            if (find(v) == v) 
                if (f[w[v] % i]) {
                    s = f[w[v] % i], t = v;
                    break;
                }
            f[w[v] % i] = v;
        }
        ans[i] = {s, t}; 
        s = find(s), t = find(t);
        fa[t] = s;         
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; i ++ ) 
        cout << ans[i].first << " " << ans[i].second << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
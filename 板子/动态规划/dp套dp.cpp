#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 2);
    vector<int> lst(n + 1, -1);
    for (int i = 1; i <= 2 * n; i ++ ) 
        cin >> a[i];
    vector<int> f(n + 1);
    for (int r = 0; r <= 2 * n + 1; r ++ ) {
        if (!~lst[a[r]]) {
            lst[a[r]] = r;
            continue;
        }
        vector<int> g(2 * n + 2);
        int l = lst[a[r]];
        g[l] = a[l];
        for (int i = l + 1; i < r; i ++ ) {
            g[i] = g[i - 1] + a[r];
            if (a[i] > a[r] && i != lst[a[i]] && lst[a[i]] > l) 
                g[i] = max(g[i], g[lst[a[i]] - 1] + f[a[i]]); 
        }
        f[a[r]] = g[r - 1] + a[r];
    }
    cout << f[0] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
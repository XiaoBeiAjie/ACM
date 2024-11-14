#include <bits/stdc++.h>
using namespace std;
const int N = 3000010, M = 200010;
typedef long long LL;

int n, m;
int f[N];
map<int, vector<int>> mp;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int x, y;
        cin >> x >> y;
        x ++, y ++;
        mp[y].push_back(x);
        m = max(m, y);
    }
    for (int i = 1; i <= m; i ++ ) {
        f[i] = f[i - 1];
        if (mp.find(i) != mp.end()) 
            for (auto u : mp[i])
                f[i] = max(f[i], f[u - 1] + i - u + 1);
    }
    cout << f[m] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
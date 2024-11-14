#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &it : w) 
        cin >> it;
    vector<int> pos;
    for (int i = 0; i < n; i ++ ) 
        if (w[i] == 1) 
            pos.push_back(i);
    int m = pos.size();
    vector<vector<int>> f(n + 1, vector<int> (m + 1, 0x3f3f3f3f));
    f[0][0] = 0;
    for (int i = 0; i < n; i ++ ) 
        for (int j = 0; j <= m; j ++ ) {
            if (f[i][j] == 0x3f3f3f3f) continue;
            f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            if (j <m && w[i] == 0)
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + abs(pos[j] - i));
        }
    cout << f[n][m] << endl;      
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
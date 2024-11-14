#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

set<pair<int, int>> mp;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};

void solve() {
    int n; cin >> n;
    double ans = 0;
    for (int i = -1; i <= 101; i ++ ) 
        mp.insert({-1, i}), mp.insert({i, -1}), mp.insert({101, i}), mp.insert({i, 101});
    while (n -- ) {
        int x, y;
        cin >> x >> y;
        double res = 2;
        if (mp.find({x, y}) != mp.end()) continue;
        mp.insert({x, y});
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + dx[i], ny = y + dy[i];
            if (mp.find({nx, ny}) != mp.end()) res -= 0.5;
        }
        ans += res;
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
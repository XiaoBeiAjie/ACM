#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    map<string, array<int, 4>> mp;
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        mp[s][0] = a, mp[s][1] = b;
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i ++ ) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        mp[s][2] = a, mp[s][3] = b;
    }
    int idx1 = 1, idx2 = 1;
    int p1 = mp["lzr010506"][0], p2 = mp["lzr010506"][2], f1 = mp["lzr010506"][1], f2 = mp["lzr010506"][3];
    for (auto [x, y] : mp) {
        if (x == "lzr010506") continue;
        if (y[0] && y[2]) continue;
        if (y[0]) {
            if (y[0] > p1) idx1 ++;
            else if (y[0] == p1 && y[1] < f1) idx1 ++;
        } 
        else if (y[2]) {
            if (y[2] > p2) idx2 ++;
            else if (y[2] == p2 && y[3] < f2) idx2 ++;
        }
    }
    cout << min(idx1, idx2) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
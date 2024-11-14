#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    map<int, int> mp1, mp12, mp21, mp32, mp23, mp31, mp13, mp14, mp41, mp2, mp3, mp4, mp5;
    ll ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        if (s.size() == 1) {
            int a = s[0] - '0';
            mp1[a] ++;
        }
        else if (s.size() == 2)  {
            int a = s[0] - '0' + s[1] - '0';
            mp2[a] ++;
        }
        else if (s.size() == 3) {
            int a = s[0] - '0' + s[1] - '0' + s[2] - '0';
            mp3[a] ++;
            mp12[s[1] - '0' + s[2] - '0' - s[0] + '0'] ++;
            mp21[s[0] - '0' + s[1] - '0' - s[2] + '0'] ++;
        }
        else if (s.size() == 4) {
            int a = s[0] - '0' + s[1] - '0' + s[2] - '0' + s[3] - '0';
            mp4[a] ++;
            mp13[s[1] - '0' + s[2] - '0' + s[3] - '0' - s[0] + '0'] ++;
            mp31[s[0] - '0' + s[1] - '0' + s[2] - '0' - s[3] + '0'] ++;
        }
        else {
            int a = s[0] - '0' + s[1] - '0' + s[2] - '0' + s[3] - '0' + s[4] - '0';
            mp5[a] ++;
            mp14[s[1] - '0' + s[2] - '0' + s[3] - '0' + s[4] - '0' - s[0] + '0'] ++;
            mp41[s[0] - '0' + s[1] - '0' + s[2] - '0' + s[3] - '0' - s[4] + '0'] ++;
            mp23[s[2] - '0' + s[3] - '0' + s[4] - '0' - s[0] + '0' - s[1] + '0'] ++;
            mp32[s[0] - '0' + s[1] - '0' + s[2] - '0' - s[3] + '0' - s[4] + '0'] ++;
        }
    }
    for (auto [x, y] : mp1) {
        ans += 1ll * y * y;
        if (mp12.find(x) != mp12.end())
            ans += 1ll * mp12[x] * y;
        if (mp21.find(x) != mp21.end())
            ans += 1ll * mp21[x] * y;
        if (mp32.find(x) != mp32.end())
            ans += 1ll * mp32[x] * y;
        if (mp23.find(x) != mp23.end())
            ans += 1ll * mp23[x] * y;
    }
    for (auto [x, y] : mp2) {
        ans += 1ll * y * y;
        if (mp13.find(x) != mp13.end()) 
            ans += 1ll * mp13[x] * y;
        if (mp31.find(x) != mp31.end())
            ans += 1ll * mp31[x] * y;
    }
    for (auto [x, y] : mp3) {
        ans += 1ll * y * y;
        if (mp14.find(x) != mp14.end())
            ans += 1ll * mp14[x] * y;
        if (mp41.find(x) != mp41.end())
            ans += 1ll * mp41[x] * y;
    }
    for (auto [x, y] : mp4) 
        ans += 1ll * y * y;
    for (auto [x, y] : mp5) 
        ans += 1ll * y * y;
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
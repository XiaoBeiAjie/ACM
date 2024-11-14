#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k, w, h;
    cin >> n >> k >> w >> h;
    string s; cin >> s;
    s = " " + s;
    bool f = false;
    int cnt = 0, x = 0, y = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == 'U') {
            if (f && y == 0) {
                f ^= 1;
                y ++;
            } 
            else if (f) {
                y --;
            }
            else if (!f && y == h) {
                f ^= 1;
                y --;
            }
            else if (!f) {
                y ++;
            }
        }
        else if (s[i] == 'D') {
            if (f && y == h) {
                f ^= 1;
                y --;
            }
            else if (f) {
                y ++;
            }
            else if (!f && y == 0) {
                f ^= 1;
                y ++;
            }
            else if (!f) {
                y --;
            }
        }
        else if (s[i] == 'L') {
            if (f && x == w) {
                f ^= 1;
                x --;
            }
            else if (f) {
                x ++;
            }
            else if (!f && x == 0) {
                f ^= 1;
                x ++;
            }
            else if (!f) {
                x --;
            }
        }
        else if (s[i] == 'R') {
            if (f && x == 0) {
                f ^= 1;
                x ++;
            }
            else if (f) {
                x --;
            }
            else if (!f && x == w) {
                f ^= 1;
                x --;
            }
            else if (!f) {
                x ++;
            }
        }
        if (!x && !y) cnt ++;
    }
    cout << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
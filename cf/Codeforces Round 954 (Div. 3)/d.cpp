#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;
int n;
string s;

bool check() {
    for (int i = 0; i < n; i ++ ) 
        if (s[i] == '0') return true;
    return false;
}

void solve() {
    cin >> n >> s;
    if ((n > 3 && check()) || (n == 3 && (s[0] == '0' || s[n - 1] == '0'))) return cout << 0 << endl, void();
    int res1 = 100, idx1 = 0, res2 = 100, idx2 = 0, res3 = 0, idx3 = 0;
    for (int i = 0; i < n - 1; i ++ ) {
        if (s[i] == '1' || s[i + 1] == '1') continue;
        int t = (s[i] - '0') * 10 + s[i + 1] - '0';
        if (t < res1) res1 = t, idx1 = i;
    }
    int ans1 = 0x3f3f3f3f;
    if (res1 != 100) {
        ans1 = res1;
        for (int i = 0; i < n; i ++ ) 
            if (i == idx1 || i == idx1 + 1) continue;
            else ans1 = min(ans1 + s[i] - '0', ans1 * (s[i] - '0'));
    }
    


    for (int i = 0; i < n - 1; i ++ ) {
        if (!((s[i] == '1' && s[i + 1] != '1') || (s[i] != '1' && s[i + 1] == '1'))) continue;
        int t = (s[i] - '0') * 10 + s[i + 1] - '0';
        if (t < res2) res2 = t, idx2 = i;
    }
    int ans2 = 0x3f3f3f3f;
    if (res2 != 100) {
        ans2 = res2;
        for (int i = 0; i < n; i ++ ) 
            if (i == idx2 || i == idx2 + 1) continue;
            else ans2 = min(ans2 + s[i] - '0', ans2 * (s[i] - '0'));
    }
    
    
    for (int i = 0; i < n - 1; i ++ ) 
        if (s[i] == '1' && s[i + 1] == '1') res3 = 11, idx3 = i;
    int ans3 = 0x3f3f3f3f;
    if (res3) {
        ans3 = 11;
        for (int i = 0; i < n; i ++ ) 
            if (i == idx3 || i == idx3 + 1) continue;
            else ans3 = min(ans3 + s[i] - '0', ans3 * (s[i] - '0'));
    }

    cout << min({ans1, ans2, ans3}) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
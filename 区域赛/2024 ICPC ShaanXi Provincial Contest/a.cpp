#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

char mp[3];

void solve() {
    string s;
    cin >> s;
    int a[3];
    for (int i = 0; i < 3; i ++ ) 
        a[i] = s[i] - '0';
    bool ans[10];
    for (int i = 0; i < 3; i ++ ) 
        for (int j = 2; j >= 0; j -- ) 
            ans[i * 3 + (2 - j)] = a[i] & (1 << j);
    for (int i = 0; i < 9; i ++ ) 
        if (ans[i]) cout << mp[i % 3];
        else cout << "-";
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    mp[0] = 'r', mp[1] = 'w', mp[2] = 'x';
    while (T -- ) solve();
    system("pause");
    return 0;
}
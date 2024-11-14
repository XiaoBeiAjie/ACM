#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s[10];
    for (int i = 1; i <= 9; i ++ ) 
        cin >> s[i], s[i] = " " + s[i];
    int x, y;
    for (int i = 2; i <= 8; i ++ ) 
        for (int j = 2; j <= 8; j ++ ) 
            if (s[i][j] == '8') {
                x = i, y = j;
                break;
            }
    for (int i = 1; i <= 9; i ++ ) {
        for (int j = 1; j <= 9; j ++ ) 
            if (i == x && j == y) cout << '8';
            else cout << '*';
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
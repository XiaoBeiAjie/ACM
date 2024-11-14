#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int idx = 0;
    for (int i = 1; i < n; i ++ ) {
        if (s[i] != '0') {
            idx = i;
            break;
        }
    }
    if (!idx) {
        cout << "-1\n";
        return ;
    }
    int a = 0, b = 0;
    for (int i = 0; i < idx; i ++ ) 
        a = a * 10 + (s[i] - '0');
    for (int i =  idx; i < n; i ++ ) 
        b = b * 10 + (s[i] - '0');
    if (a >= b) {
        cout << "-1\n";
        return ;
    }
    cout << a << " " << b << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
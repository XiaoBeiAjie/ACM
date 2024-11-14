#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (s[i] == '1') cnt1 ++;
        else cnt2 ++;
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == '1') cnt2 --;
        else cnt1 --;
        if (cnt1 < 0 || cnt2 < 0) {
            cout << n - i + 1 << "\n";
            return ;
        }
    }
    cout << "0\n";
        
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n + 1);
    if (k == 1) {
        string s;
        for (int i = 1; i <= n; i ++ ) 
            cin >> s, cout << s << endl;
        return ;
    }
    for (int i = 1; i <= n; i ++ ) {
        string ss;
        cin >> ss;
        ss = " " + ss;
        s[i] = ss;
    }
    
    char g[n][n];
    for (int i = 1; i <= n; i += k) 
        for (int j = 1; j <= n; j += k) 
            g[i / k][j / k] = s[i][j]; 
    for (int i = 0; i < n / k; i ++ ) {
        for (int j = 0; j < n / k; j ++ ) 
            cout << g[i][j];
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
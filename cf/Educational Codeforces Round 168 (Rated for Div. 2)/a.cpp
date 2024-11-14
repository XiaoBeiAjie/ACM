#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i ++ ) 
        if (s[i] == s[i + 1]) {
            if (s[i] == 'a') {
                for (int j = 0; j <= i; j ++ )
                    cout << s[j];
                cout << 'z';
                for (int j = i + 1; j < n; j ++ ) 
                    cout << s[j];
                cout << "\n";
                return ;
            }
            else {
                for (int j = 0; j <= i; j ++ )
                    cout << s[j];
                cout << 'a';
                for (int j = i + 1; j < n; j ++ ) 
                    cout << s[j];
                cout << "\n";
                return ;
            }
        }
    cout << s;
    if (s[n - 1] == 'a') cout << "b\n";
    else cout << "a\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

void solve() {
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i ++ ) 
        if (s1[i] == '0' && s2[i] != '0') return cout << "No" << endl, void();
        else if (s1[i] == '1') break;
    cout << "Yes" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
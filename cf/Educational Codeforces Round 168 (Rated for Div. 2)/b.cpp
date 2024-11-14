#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int cnt = 0;
    for (int i = 1; i <= n - 2; i ++ ) 
        if (s2[i] == 'x' && s2[i + 1] == '.' && s2[i + 2] == 'x' && s1[i] == '.' && s1[i + 1] == '.' && s1[i + 2] == '.') cnt ++;
        else if (s2[i] == '.' && s2[i + 1] == '.' && s2[i + 2] == '.' && s1[i] == 'x' && s1[i + 1] == '.' && s1[i + 2] == 'x') cnt ++;
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
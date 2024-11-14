#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long LL;



void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1, s2 = " " + s2;
    vector<int> ne(m + 1);
    for (int i = 2, j = 0; i <= m; i ++ ) {
        while (j && s2[j + 1] != s2[i]) j = ne[j];
        if (s2[j + 1] == s2[i]) j ++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i ++ ) {
        while (j && s2[j + 1] != s1[i]) j = ne[j];
        if (s2[j + 1] == s1[i]) j ++;
        if (j == m) {
            cout << i - m + 1 << endl;
            j = ne[j];
        }
    }
    for (int i = 1; i <= m; i ++ ) 
        cout << ne[i] << " ";
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
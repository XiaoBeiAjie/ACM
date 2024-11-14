#include <bits/stdc++.h>
using namespace std;
const int N = 3000010;
typedef long long LL;

int idx;
int tr[N][70];
int cnt[N];

int fun(char c) {
    if (islower(c)) return c - 'a';
    if (isupper(c)) return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(string s) {
    int n = s.size();
    int p = 0;
    for (int i = 0; i < n; i ++ ) {
        int c = fun(s[i]);
        if (!tr[p][c]) 
            tr[p][c] = ++ idx;
        p = tr[p][c];
        cnt[p] ++;
    }
}

int query(string s) {
    int n = s.size();
    int p = 0;
    for (int i = 0; i < n; i ++ ) {
        int c = fun(s[i]);
        if (!tr[p][c]) return 0;
        p = tr[p][c];
    }
    return cnt[p];
}

void solve() {
    for (int i = 0; i <= idx; i ++ ) 
        for (int j = 0; j < 65; j ++ ) 
            tr[i][j] = 0;
    for (int i = 0; i <= idx; i ++ ) 
        cnt[i] = 0;
    idx = 0;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) {
        string s;
        cin >> s;
        insert(s);
    }
    while (q -- ) {
        string s;
        cin >> s;
        cout << query(s) << endl;
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
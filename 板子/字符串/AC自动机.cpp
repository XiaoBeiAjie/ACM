#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
typedef long long LL;

struct Aho_Corasick_Automaton {
    int tr[N][65], cnt[N], fail[N], idx;
    queue<int> q;

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
        }
        cnt[p] ++;
    }

    void build() {
        for (int i = 0; i < 26; i ++ ) 
            if (tr[0][i])
                fail[tr[0][i]] = 0, q.push(tr[0][i]);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i ++ ) 
                if (tr[u][i]) 
                    fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
                else 
                    tr[u][i] = tr[fail[u]][i];
        }
    }

    int query(string s) {
        int n = s.size(), p = 0, ans = 0;
        for (int i = 0; i < n; i ++ ) {
            int c = fun(s[i]);
            p = tr[p][c];
            for (int t = p; t && ~cnt[t]; t = fail[t])
                ans += cnt[t], cnt[t] = -1;
        }
        return ans;
    }
}AC;

void solve() {
    int n; cin >> n;
    while (n -- ) {
        string s;
        cin >> s;
        AC.insert(s);
    }
    AC.build();
    string s;
    cin >> s;
    cout << AC.query(s) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
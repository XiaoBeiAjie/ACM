#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i ++ ) 
        s[i] -='0';
    int m; cin >> m;
    string l, r; cin >> l >> r;
    for (int i = 0; i < m; i ++ ) 
        l[i] -= '0', r[i] -= '0';
    int i = 0, j = 0;
    while (i < n && j < m) {
        vector<int> vis(10);
        int cnt = 0;
        for (int idx = l[j]; idx <= r[j]; idx ++ ) 
            vis[idx] = true, cnt ++;
        while (cnt && i < n) {
            if (vis[s[i]]) 
                cnt --, vis[s[i]] = false;
            i ++;
        }
        if (!cnt) j ++;    
    }
    cout << (j == m ? "No\n" : "Yes\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
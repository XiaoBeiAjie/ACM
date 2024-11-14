#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        mp[x].push_back(i);
    } 
    set<vector<int>> st;
    for (auto [u , v] : mp) 
        if (v.size() != 1) st.insert(v);
    int len = st.size();
    int m; cin >> m;
    while (m -- ) {
        string s; cin >> s;
        if (s.size() != n) {
            cout << "No\n";
            continue;
        }
        s = " " + s;
        map<int, vector<int>> cnt;
        for (int i = 1; i <= n; i ++ ) 
            cnt[s[i] - 'a'].push_back(i);
        bool f = true;
        int idx = 0;
        for (auto [u, v] : cnt) {
            if (v.size() != 1) {
                if (st.find(v) == st.end()) {
                    f = false;
                    break;
                }
                else idx ++;
            }
            
        }
            
        cout << ((f && idx == len) ? "Yes\n" : "No\n");
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
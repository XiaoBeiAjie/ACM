#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
typedef long long LL;

int n;
int f[N], pre[N];
string s[N];
map<vector<int>, int> mp;

void print(int u) {
    if (!u) return ;
    print(pre[u]);
    cout << s[u] << endl;
}


void solve() {
    while (cin >> s[++ n]);
    for (int i = 1; i < n; i ++ ) {
        f[i] = 1;
        vector<int> v(26);
        for (auto u : s[i])
            v[u - 'a'] ++;
        mp[v] = i;
    }
    for (auto [x, y] : mp) {
        vector<int> v = x;
        for (int i = 0; i < 26; i ++ ) {
            v[i] ++;
            if (mp.find(v) != mp.end() && f[mp[v]] < f[y] + 1) {
                f[mp[v]] = f[y] + 1;
                pre[mp[v]] = y;
            }
            v[i] --;   
        }    
    }
    int idx = 0;
    for (int i = 1; i < n; i ++ ) 
        if (f[i] > f[idx]) idx = i;
    cout << f[idx] << endl;
    print(idx);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
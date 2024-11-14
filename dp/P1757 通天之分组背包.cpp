#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, m;
unordered_map<int, vector<int>> v, w;
unordered_map<int, int> mp;
int idx;
int f[N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        if (mp.find(c) == mp.end()) mp[c] = ++ idx;
        c = mp[c];
        w[c].push_back(a);
        v[c].push_back(b);
    }
    for (int i = 1; i <= idx; i ++ ) 
        for (int j = m; j >= 0; j -- ) 
            for (int k = 0; k < v[i].size(); k ++ ) 
                if (j >= w[i][k]) f[j] = max(f[j - w[i][k]] + v[i][k], f[j]);
    cout << f[m] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
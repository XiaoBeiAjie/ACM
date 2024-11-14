#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long LL;

int n, m;
int a[N], b[N], c[N];

int f[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    for (int i = 1; i <= m; i ++ ) cin >> c[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i ++ ) 
        if (mp.find(a[i]) == mp.end()) mp[a[i]] = a[i] - b[i];
        else mp[a[i]] = min(mp[a[i]], a[i] - b[i]);
    sort(c + 1, c + 1 + n, greater<int>());
    for (int i = 1; i <= m; i ++ ) {
        
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
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int i = 1; i <= n; i ++ ) 
        cin >> b[i];
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i ++ ) 
        if (a[i] > b[i]) ans ++;
        else if (a[i] == b[i]) cnt ++;
    cout << ans + (cnt + 1) / 2 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n;
LL w[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    LL last = w[1], ans = 0, maxx = 0;
    for (int i = 2; i <= n; i ++ ) {
        last = max(last, w[i]);
        ans += last - w[i];
        maxx = max(maxx, last - w[i]);
    }
    cout << ans + maxx << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
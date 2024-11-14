#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    int st = n + 1, ed = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        if (w[i] == 1) 
            st = min(st, i), ed = max(ed, i);
    }
    int cnt = 0;
    for (int i = st; i <= ed; i ++ ) 
        if (!w[i])
            cnt ++;
    cout << cnt << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i];
    if (n < (k << 1)) return cout << "impossible\n", void();
    if (k == 1) {
        
    } else {
        int t = 2000;
        for (int i = 1; i < n; i ++ ) 
            t = min(t, w[i] + w[i + 1]);
        cout << t << endl;
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
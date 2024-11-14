#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], cnt[w[i]] ++;
    int idx = 0;
    for (int i = 0; i < n; i ++ ) 
        if (!cnt[i]) return cout << i << "\n", void();
        else if (cnt[i] == 1)
            if (!idx) idx ++;
            else return cout << i << "\n", void();
    cout << n << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
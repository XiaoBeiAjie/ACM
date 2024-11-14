#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], sum += w[i];
    ll avg = sum / n;
    ll res = 0, idx = avg;
    for (int i = n; i; i -- ) {
        res += w[i];
        if (res > idx) 
            return cout << "No\n", void();
        idx += avg;
    }
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
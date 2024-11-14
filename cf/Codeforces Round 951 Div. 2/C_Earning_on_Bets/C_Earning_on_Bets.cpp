#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n + 10);
    vector<LL> ans(n + 10);
    LL LCM = 1, sum = 0;
    for (int i = 1; i <= n; i ++ ) cin >> v[i], LCM = lcm(v[i], LCM);
    for (int i = 1; i <= n; i ++ ) ans[i] = LCM / v[i], sum += ans[i];
    for (int i = 1; i <= n; i ++ ) 
        if (ans[i] * v[i] <= sum) return cout << "-1\n", void();
    for (int i = 1; i <= n; i ++ ) 
        cout << ans[i] << " ";
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
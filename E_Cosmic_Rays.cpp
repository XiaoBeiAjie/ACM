#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    int n; cin >> n;
    stack<array<i64, 2>> stk;
    i64 ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        i64 a, b; cin >> a >> b;
        i64 lst = 0;
        while (!stk.empty()) {
            if (stk.top()[1] == b) {
                i64 aa = stk.top()[0]; stk.pop();
                a = aa + a - lst;
            }
            else if (stk.top()[0] < a) lst = stk.top()[0], stk.pop();
            else if (stk.top()[0] >= a) break;
        }
        if (stk.empty()) ans = a;
        stk.push({a, b});
        cout << ans << " \n"[i == n];
    }
}

bool mem2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    cerr << fixed << setprecision(2) << "Memory : " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB\n";
    #endif
    int T; cin >> T;
    while (T -- ) solve();
    #ifdef LOCAL
    cerr << "Time : " << clock() * 1000 / CLOCKS_PER_SEC << "MS\n";
    #endif
    return 0;
}
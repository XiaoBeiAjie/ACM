#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool mem1;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    stack<int> stk;
    for (int i = 1; i <= n; i ++ ) 
        if (s[i] == '0') stk.push(i);
    int r = n, l = 1;
    i64 cnt = 0;
    while (l <= r) {
        int j = r - 1;
        bool ok = false;
        while (j && s[j] == '0') {
            if (!stk.empty() && j == stk.top()) {
                ok = true;
                cnt += j;
                stk.pop();
            }
            j --;
        }
        if (!ok) {
            if (!stk.empty()) {cnt += stk.top(); stk.pop();}
            else {
                while (l <= r && s[l] == '0') l ++;
                cnt += l ++;
            }
        }
            
        r = j;
    }
    cout << cnt << "\n";
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
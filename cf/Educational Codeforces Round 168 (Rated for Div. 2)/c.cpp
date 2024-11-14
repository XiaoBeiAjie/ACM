#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    stack<int> stk;
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == '_') {
            if (!stk.empty()) 
                ans += i - stk.top(), stk.pop();
            else stk.push(i);
        }
        else if (s[i] == '(') 
            stk.push(i);
        else 
            ans += i - stk.top(), stk.pop();
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
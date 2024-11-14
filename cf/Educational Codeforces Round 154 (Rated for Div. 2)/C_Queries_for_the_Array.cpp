#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int idx = 0, cnt = 0, n = s.size();
    stack<int> stk;
    set<int> st1, st2;
    s = " " + s;
    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == '+') stk.push(++ idx), cnt ++;
        else if (s[i] == '-') {
            if (st1.find(stk.top()) != st1.end()) 
                st1.erase(stk.top());
            stk.pop(), cnt --;
        }
        else if (s[i] == '0') {
            if (cnt < 2) 
                return cout << "No\n", void();
            else if (lower_bound(st2.begin(), st2.end(), stk.top()) != st2.end()) 
                return cout << "No\n", void();
            else 
                st1.insert(stk.top());
        }
        else if (s[i] == '1') {
            if (!st1.empty()) 
                return cout << "No\n", void();
            else if (cnt) 
                st2.insert(stk.top()); 
        }
    }
    cout << "Yes\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
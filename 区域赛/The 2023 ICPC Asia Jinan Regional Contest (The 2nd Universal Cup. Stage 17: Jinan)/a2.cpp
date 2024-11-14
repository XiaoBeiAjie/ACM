#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 100010;
typedef long long LL;

int T;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++ ) 
        if (s[i] == ')') s[i] = '(';
        else if (s[i] == ']') s[i] = '[';
    stack<char> stk;
    bool f = 1;
    int cnt = 0;
    char last = s[0];
    for (int i = 0; i < s.size(); i ++ ) {
        if (stk.empty()) {
            cnt ++, f = 0, stk.push(s[i]);
            if (cnt != 1 && s[i] == last) return cout << "No" << endl, void(); 
            else s[i] = last;
        }
        else {
            if (!f) {
                if (stk.top() != s[i]) stk.push(s[i]);
                else stk.pop(), f = 1;
            }
            else {
                if (stk.top() == s[i]) stk.pop();
                else return cout << "No" << endl, void();
            }
        } 
    }
    if (cnt > 2 || !stk.empty()) return cout << "No" << endl, void();
    cout << "Yes" << endl;
}

int main(void) {
    scanf("%d", &T);
    while (T -- ) solve();
    system("pause");
    return 0;
}
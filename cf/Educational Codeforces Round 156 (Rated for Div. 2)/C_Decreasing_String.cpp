#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    string s; cin >> s;
    ll pos; cin >> pos;
    ll len = s.size(), cnt = 0;
    ll n = s.size();
    while (pos > len) 
        pos -= len --, cnt ++;
    stack<int> stk;
    for (int i = 0; i < n && cnt; i ++ ) {
        while (!stk.empty() && cnt && s[stk.top()] > s[i]) {
            cnt --;
            s[stk.top()] = '@';
            stk.pop();
        }
        stk.push(i);
    }
    cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] != '@') {
            cnt ++;
            if (cnt == pos) 
                return cout << s[i], void();
        }
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
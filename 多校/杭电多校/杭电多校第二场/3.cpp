#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

set<array<int,3>> s;

void solve() {
    string ss[10];
    for (int i = 1; i <= 9; i ++ ) {
        cin >> ss[i]; ss[i] = " " + ss[i];
    }
    int a, b, c;
    a = ss[4][4] - '0', b = ss[3][4] - '0', c = ss[4][3] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[4][6] - '0', b = ss[4][7] - '0', c = ss[3][6] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[6][6] - '0', b = ss[7][6] - '0', c = ss[6][7] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[6][4] - '0', b = ss[6][3] - '0', c = ss[7][4] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[1][4] - '0', b = ss[4][12] - '0', c = ss[4][1] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[1][6] - '0', b = ss[4][9] - '0', c = ss[4][10] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[9][4] - '0', b = ss[6][1] - '0', c = ss[6][12] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    a = ss[9][6] - '0', b = ss[6][10] - '0', c = ss[6][9] - '0';
    if (s.find({a, b, c}) == s.end()) {
        cout << min({a, b, c}) << " " << a + b + c - min({a, b, c}) - max({a, b, c}) << " " << max({a, b, c}) << "\n";
        return ;
    }
    cout << "No problem\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    s.insert({3,1,2});
    s.insert({3,4,1});
    s.insert({3,6,4});
    s.insert({3,2,6});
    s.insert({6,4,3});
    s.insert({6,5,4});
    s.insert({6,2,5});
    s.insert({6,3,2});
    s.insert({4,1,3});
    s.insert({4,5,1});
    s.insert({4,6,5});
    s.insert({4,3,6});
    s.insert({1,5,2});
    s.insert({1,4,5});
    s.insert({1,3,4});
    s.insert({1,2,3});
    s.insert({2,1,5});
    s.insert({2,3,1});
    s.insert({2,6,3});
    s.insert({2,5,6});
    s.insert({5,1,4});
    s.insert({5,2,1});
    s.insert({5,6,2});
    s.insert({5,4,6});
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
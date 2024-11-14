#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w;
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        int idx = 0, len = s.size();
        sum += len;
        while (s[len - 1 - idx] == '0') idx ++;
        if (idx) w.push_back(idx);
    }
    if (!w.empty()) {
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        sum -= w[0];
        for (int i = 2; i < w.size(); i += 2 ) 
            sum -= w[i];
    }
    if (sum > m) cout << "Sasha\n";
    else cout << "Anna\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
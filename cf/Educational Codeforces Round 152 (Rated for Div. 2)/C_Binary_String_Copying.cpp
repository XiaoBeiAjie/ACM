#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    vector<int> pre(n + 1), suf(n + 1);
    suf[n] = n;
    for (int i = n - 1; i; i -- ) {
        if (s[i + 1] == '1') suf[i] = suf[i + 1];
        else suf[i] = i;
    }
    pre[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (s[i - 1] == '0') pre[i] = pre[i - 1];
        else pre[i] = i;
    }
    vector<int> pre1(n + 1), suf1(n + 1);
    suf1[n] = n;
    for (int i = n - 1; i; i -- ) {
        if (s[i + 1] >= s[i]) suf1[i] = suf1[i + 1];
        else suf1[i] = i;
    }
    pre1[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (s[i - 1] <= s[i]) pre1[i] = pre1[i - 1];
        else pre1[i] = i;
    }
    set<pair<int, int>> st;
    bool f = false;
    while (m -- ) {
        int l, r;
        cin >> l >> r;
        //cerr << "<<" << l << " " << r << " " << pre[l] << " " << suf[r] << "\n";
        if (suf1[l] >= r) {
            f = true;
            continue;
        }
        l = pre[l], r = suf[r];
        if (st.find({l, r}) == st.end()) st.insert({l, r});
    }
    cout << st.size() + f << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
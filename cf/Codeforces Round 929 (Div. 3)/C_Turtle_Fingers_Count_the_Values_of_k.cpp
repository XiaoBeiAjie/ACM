#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, l;
    cin >> a >> b >> l;
    set<int> st;
    for (ll i = 1; i <= l; i *= a) 
        for (ll j = 1; i * j <= l; j *= b) 
            if (l % (i * j) == 0 && st.find(l / (i * j)) == st.end()) 
                st.insert(l / (i * j));
    cout << st.size() << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
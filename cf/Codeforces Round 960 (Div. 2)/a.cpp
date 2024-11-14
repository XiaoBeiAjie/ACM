#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> v[i];
    sort(v.begin() + 1, v.end());
    int cnt = 0, last = 0;
    for (int i = n; i; i -- ) {
        if (v[i] == last) 
            cnt ++;
        else {
            if (cnt & 1) return cout << "Yes" << endl, void();
            cnt = 1, last = v[i];
        }
    }
    if (cnt & 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
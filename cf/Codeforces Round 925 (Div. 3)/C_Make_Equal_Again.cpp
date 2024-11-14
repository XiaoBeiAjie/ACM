#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> w(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i ++ ) 
        cin >> w[i], cnt[w[i]] ++;
    int l = 1;
    while (l <= n && w[l] == w[1]) l ++;
    int r = n;
    while (r && w[r] == w[n]) r --;
    l --, r ++;
    if (l >= r) return cout << "0\n", void(); 
    r = n + 1 - r;
    if (w[1] == w[n]) return cout << n - l - r << "\n", void();
    cout << n - max(l, r) << "\n";
}    

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
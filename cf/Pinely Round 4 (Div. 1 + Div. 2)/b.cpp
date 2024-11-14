#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i < n; i ++ )
        cin >> b[i];
    vector<int> a(n + 1);
    a[1] = b[1];
    for (int i = 2; i < n; i ++ ) 
        a[i] = b[i] | b[i - 1];
    a[n] = b[n - 1];
    for (int i = 1; i < n; i ++ ) 
        if (b[i] != (a[i] & a[i + 1])) 
            return cout << "-1\n", void();
    for (int i = 1; i <= n; i ++ ) 
        cout << a[i] << " ";
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
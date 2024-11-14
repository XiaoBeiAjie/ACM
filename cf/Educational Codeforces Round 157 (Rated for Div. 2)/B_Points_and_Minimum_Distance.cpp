#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i ++ ) 
        cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[n] - a[1] + a[2 * n] - a[n + 1] << "\n";
    for (int i = 1; i <= n; i ++ ) 
        cout << a[i] << " " << a[n + i] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
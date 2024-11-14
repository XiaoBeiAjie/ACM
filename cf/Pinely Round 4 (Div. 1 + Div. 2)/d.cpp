#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

int a[] = {1, 1, 2, 2, 3, 3, 4};

void solve() {
    int n; cin >> n;
    int idx = 1;
    vector<int> ans(n + 1);
    if (n <= 6) {
        cout << a[n] << "\n";
        for (int i = 1; i <= n; i ++ ) 
            cout << a[i] << " \n"[i == n];
        return ;
    }
    cout << "4\n";
    for (int i = 1; i <= n; i ++ ) 
        cout << i % 4 + 1 << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
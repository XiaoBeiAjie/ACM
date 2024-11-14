#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;

int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 0; j < k; j ++ ) 
            printf("%c", 'a' + j);
    cout << endl;
}

int main(void) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;


void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) cout << "Walk Alone" << endl;
    else cout << "Kelin" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    system("pause");
    return 0;
}
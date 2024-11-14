#include <bits/stdc++.h>
using namespace std;int T = 1;
typedef long long ll;

void solve() {
    int n, k;
    while (cin >> n >> k, n) 
        cout << ((n - 1) % (k + 1) ? "Tang\n" : "Jiang\n");
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
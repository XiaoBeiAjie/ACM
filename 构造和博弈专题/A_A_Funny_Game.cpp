#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    while (cin >> n, n) 
        cout << (n < 3 ? "Alice\n" : "Bob\n"); 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while (T -- ) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    int a = max(1, n - 52);
    int b = max(1, n - a - 26);
    int c = n - a - b;
    char aa = 'a' + a - 1;
    char bb = 'a' + b - 1;
    char cc = 'a' + c - 1;
    cout << aa << bb << cc << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
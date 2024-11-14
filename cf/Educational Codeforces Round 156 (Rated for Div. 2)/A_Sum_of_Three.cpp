#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int n; cin >> n;
    if (n % 3 == 0) {
        int a = 1, b = 4, c = n - 5;
        if (c <= 0 || c == 1 || c == 4)
            return cout << "No\n", void();
        cout << "Yes\n";
        cout << a << " " << b << " " << c << "\n";
            
    }
    else if (n % 3 == 1) {
        int a = 1, b = 2, c = n - 3;
        if (c <= 0 || c == 1 || c == 2) 
            return cout << "No\n", void();
        cout << "Yes\n";
        cout << a << " " << b << " " << c << "\n";
    }
    else {
        int a = 1, b = 2, c = n - 3;
        if (c <= 0 || c == 1 || c == 2) 
            return cout << "No\n", void();
        cout << "Yes\n";
        cout << a << " " << b << " " << c << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
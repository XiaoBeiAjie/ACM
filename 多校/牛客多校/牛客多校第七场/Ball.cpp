#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl "\n"
void solve() {
    long double l , x ,y;
    cin >> l >> x >> y;
    if (x * x + y * y <= l * l) {
        cout << "Yes\n0\n";
        return ;
    }
    if ((x - l) * (x - l) + y * y <= l * l) {
        cout << "Yes\n" << l << "\n";
        return ;
    }
    cout << "No" << endl;
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    return 0;
}
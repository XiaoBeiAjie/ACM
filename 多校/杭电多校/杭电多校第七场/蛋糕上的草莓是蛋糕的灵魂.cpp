#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
#define endl "\n"
void solve() {
    ll x , y;
    cin >> x >> y;
    cout << y << " " <<  x  / __gcd(x , y)   << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    //system("pause");
    return 0;
}
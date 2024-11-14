#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    function<int(int)> lowbit = [&] (int x) {
        return x & -x;
    }; 
    if (lowbit(a) == lowbit(b)== lowbit(c)) cout << "NO\n";
    else cout << "YES\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}
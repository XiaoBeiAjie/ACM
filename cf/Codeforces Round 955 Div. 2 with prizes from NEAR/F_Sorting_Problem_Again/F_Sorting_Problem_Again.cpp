#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;



void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 <= y2 && y2 <= y1) || (x1 <= x2 && x2 <= y1) || (x2 <= x1 && x1 <= y2) || (x2 <= y1 && y1 <= y2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T -- ) solve();
    system("pause");
    return 0;
}